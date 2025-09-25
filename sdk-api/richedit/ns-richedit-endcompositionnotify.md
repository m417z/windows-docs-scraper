# ENDCOMPOSITIONNOTIFY structure

## Description

Contains information about an EN_ENDCOMPOSITION notification code from a rich edit control.

## Members

### `nmhdr`

The **code** member of this structure identifies the notification code being sent.

### `dwCode`

Indicates the state of the composition. This member is one of the following values.

| Value | Meaning |
| --- | --- |
| **ECN_ENDCOMPOSITION**<br><br>1 | The composition is complete. |
| **ECN_NEWTEXT**<br><br>2 | There are new characters in the composition. |