# ImmNotifyIME function

## Description

Notifies the IME about changes to the status of the input context.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `dwAction` [in]

Notification code. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **NI_CHANGECANDIDATELIST** | An application changed the current selected candidate. The *dwIndex* parameter specifies an index of a candidate list to be selected and *dwValue* is not used. |
| **NI_CLOSECANDIDATE** | An application directs the IME to close a candidate list. The *dwIndex* parameter specifies an index of the list to close, and *dwValue* is not used. The IME sends a [IMN_CLOSECANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-closecandidate) command to the application if it closes the list. |
| **NI_COMPOSITIONSTR** | An application directs the IME to carry out an action on the composition string. The *dwIndex* parameter can be CPS_CANCEL, CPS_COMPLETE, CPS_CONVERT, or CPS_REVERT. |
| **NI_IMEMENUSELECTED** | An application directs the IME to allow the application to handle the specified menu. The *dwIndex* parameter specifies the ID of the menu and *dwValue* is an application-defined value for that menu item. |
| **NI_OPENCANDIDATE** | An application directs the IME to open a candidate list. The *dwIndex* parameter specifies the index of the list to open, and *dwValue* is not used. The IME sends a [IMN_OPENCANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-opencandidate) command to the application if it opens the list. |
| **NI_SELECTCANDIDATESTR** | An application has selected one of the candidates. The *dwIndex* parameter specifies an index of a candidate list to be selected. The *dwValue* parameter specifies an index of a candidate string in the selected candidate list. |
| **NI_SETCANDIDATE_PAGESIZE** | The application changes the page size of a candidate list. The *dwIndex* parameter specifies the candidate list to be changed and must have a value in the range 0 to 3. The *dwValue* parameter specifies the new page size. |
| **NI_SETCANDIDATE_PAGESTART** | The application changes the page starting index of a candidate list. The *dwIndex* parameter specifies the candidate list to be changed and must have a value in the range 0 to 3. The *dwValue* parameter specifies the new page start index. |

### `dwIndex` [in]

Index of a candidate list. Alternatively, if *dwAction* is NI_COMPOSITIONSTR, this parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **CPS_CANCEL** | Clear the composition string and set the status to no composition string. |
| **CPS_COMPLETE** | Set the composition string as the result string. |
| **CPS_CONVERT** | Convert the composition string. |
| **CPS_REVERT** | Cancel the current composition string and set the composition string to be the unconverted string. |

### `dwValue` [in]

Index of a candidate string. The application can set this parameter or ignore it, depending on the value of the *dwAction* parameter.

## Return value

Returns nonzero if successful, or 0 otherwise.

## See also

[IMN_CLOSECANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-closecandidate)

[IMN_OPENCANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-opencandidate)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)