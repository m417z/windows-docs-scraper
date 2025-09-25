# CHANGENOTIFY structure

## Description

Contains information that is associated with an [EN_CHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-change--rich-edit-control-) notification code. A windowless rich edit control sends this notification to its host window when the content of the control changes.

## Members

### `dwChangeType`

The type of change that occurred. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **CN_GENERIC** | No significant change occurred. |
| **CN_NEWREDO** | A new redo action was added. |
| **CN_NEWUNDO** | A new undo action was added. |
| **CN_TEXTCHANGED** | The text changed. |

### `pvCookieData`

Cookie for the undo action
that is associated with the change.

## See also

[EN_CHANGE](https://learn.microsoft.com/windows/desktop/Controls/en-change--rich-edit-control-)