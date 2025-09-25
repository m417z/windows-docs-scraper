# SFVM_HELPTOPIC_DATA structure

## Description

Contains the name of an HTML Help file and a topic in that file. Used with the [SFVM_GETHELPTOPIC](https://learn.microsoft.com/windows/desktop/shell/sfvm-gethelptopic) notification. This structure requires Unicode strings.

## Members

### `wszHelpFile`

Type: **WCHAR[MAX_PATH]**

A null-terminated Unicode string containing the fully qualified path to the help file.

### `wszHelpTopic`

Type: **WCHAR[MAX_PATH]**

A null-terminated Unicode string containing the name of the topic.