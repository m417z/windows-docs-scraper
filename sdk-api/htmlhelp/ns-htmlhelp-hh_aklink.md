# HH_AKLINK structure

## Description

Use this structure to specify one or more ALink names or KLink keywords that you want to search for.

## Members

### `cbStruct`

Specifies the size of the structure. This value must always be filled in before passing the structure to the HTML Help API.

### `fReserved`

This parameter must be set to FALSE.

### `pszKeywords`

Specifies one or more ALink names or KLink keywords to look up. Multiple entries are delimited by a semicolon.

### `pszUrl`

Specifies the topic file to navigate to if the lookup fails. *pszURL* refers to a [valid topic](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-html-help-urls) within the specified compiled help (.chm) file and does not support Internet protocols that point to an HTML file.

### `pszMsgText`

Specifies the text to display in a message box if the lookup fails and *fIndexOnFail* is FALSE and *pszURL* is NULL.

### `pszMsgTitle`

Specifies the caption of the message box in which the *pszMsgText* parameter appears.

### `pszWindow`

Specifies the name of the window type in which to display one of the following:

* The selected topic, if the lookup yields one or more matching topics.
* The topic specified in *pszURL*, if the lookup fails and a topic is specified in *pszURL*.

The Index tab, if the lookup fails and *fIndexOnFail* is specified as TRUE.

### `fIndexOnFail`

Specifies whether to display the keyword in the Index tab of the HTML Help Viewer if the lookup fails. The value of *pszWindow* specifies the Help Viewer.

## Remarks

* ALink name and KLink keyword lookups are case sensitive, and multiple keywords are delimited by a semicolon.
* If the lookup yields one or more matching topics, the topic titles appear in the Topics Found dialog box.

If the lookup yields no matching topics, **HtmlHelp()** checks the values of the following **HH_AKLINK** members to determine what alternative action to take:

* *fIndexOnFail*. If *fIndexOnFail* is TRUE, the Index tab is selected in the help window specified in *pszWindow*, and the keyword specified in *pszKeyword* is selected in the entry field.
* *pszURL*. If *fIndexOnFail* is FALSE, the topic file specified in *pszURL* appears in the help window specified in *pszWindow*.
* *pszMsgText* and *pszMsgTitle*. If *fIndexOnFail* is FALSE and *pszURL* is NULL, a message box appears using the text and caption specified in *pszMsgText* and *pszMsgTitle*.

### Used by

* [HH_ALINK_LOOKUP](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-alink-lookup-command)
* [HH_KEYWORD_LOOKUP](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/hh-keyword-lookup-command)

## See also

[About Structures](https://learn.microsoft.com/previous-versions/windows/desktop/htmlhelp/about-structures)