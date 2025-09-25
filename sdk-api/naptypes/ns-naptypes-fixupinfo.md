# FixupInfo structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **FixupInfo** structure contains fix-up information for the Sysytem Health Agent (SHA).

## Members

### `state`

A [FixupState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-fixupstate) value that defines the fix-up state of the SHA.

### `percentage`

A [Percentage](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) data type that contains the percentage of remediation that is complete. This member is a nonzero value between 0 (zero) and 100 when **state** is equal to [FixupStateInProgress](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-fixupstate); otherwise, it is 0 (zero).

**Note** If the SHA does not support percentages, this value is either 0, which indicates the SHA update has not started; or 101, which indicates the SHA is in the process of updating.

### `resultCodes`

A [ResultCodes](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-resultcodes) structure that contains the SHA defined HRESULT values returned to the NAP Agent in a call to [GetFixupInfo](https://learn.microsoft.com/windows/desktop/NAP/inapsystemhealthagentcallback-getfixupinfo-method).

### `fixupMsgId`

A [MessageID](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) value that contains the SHA defined resource ID of a fix-up status structure.

## Remarks

If your SHA remediation process supports the reporting of percentage values during update, **percentage** is used to communicate the current progress as an integer percentage value. When the remediation update is complete, **percentage** must be set to 100, and **state** must be set to **fixupStateSuccess**. If remediation is not complete, **percentage** must be set to a value between 0 and 99, inclusive, and **state** must be set to **fixupStateInProgress**.

If your remediation process does not support the reporting of percentage values, then as long as **state** is set to **fixupStateInProgress**, **percentage** must be set to a value of 101, which indicates the remediation process is in a general "updating" state but the amount of completion is unknown. When remediation completes, **state** must be set to **fixupStateSuccess** and **percentage** must be set to 100.

If the SHA cannot update the fix-up information, then **state** must be set to **fixupStateCouldNotUpdate**.

## See also

[FixupState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-fixupstate)

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)

[ResultCodes](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-resultcodes)