/*
 * ChaiScriptSyntaxHighlighter.hpp
 *
 *  Created on: 21.10.2016
 *      Author: klemens.morgenstern
 */

#ifndef WIDGETS_CHAISCRIPTSYNTAXHIGHLIGHTER_HPP_
#define WIDGETS_CHAISCRIPTSYNTAXHIGHLIGHTER_HPP_

#include <QSyntaxHighlighter>

namespace widgets {

class ChaiScriptRule
{
public:
	ChaiScriptRule(const QString &patternStr, int n, const QTextCharFormat &matchingFormat)
    {
        originalRuleStr = patternStr;
        pattern = QRegExp(patternStr);
        nth = n;
        format = matchingFormat;
    }
    QString originalRuleStr;
    QRegExp pattern;
    int nth;
    QTextCharFormat format;
};

//! Implementation of highlighting for Python code.
class ChaiScriptSyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    ChaiScriptSyntaxHighlighter(QTextDocument *parent = 0);
protected:
    void highlightBlock(const QString &text);
private:
    QStringList keywords;
    QStringList operators;
    QStringList braces;

    QHash<QString, QTextCharFormat> basicStyles;

    void initializeRules();

    //! Highlighst multi-line strings, returns true if after processing we are still within the multi-line section.
    bool matchMultiline(const QString &text, const QRegExp &delimiter, const int inState, const QTextCharFormat &style);
    const QTextCharFormat getTextCharFormat(const QString &colorName, const QString &style = QString());

    QList<ChaiScriptRule> rules;
};

} /* namespace widgets */

#endif /* WIDGETS_CHAISCRIPTSYNTAXHIGHLIGHTER_HPP_ */