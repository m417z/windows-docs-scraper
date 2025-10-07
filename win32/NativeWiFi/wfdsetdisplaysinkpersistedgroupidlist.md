# WFDDisplaySinkSetPersistedGroupIDList function

Sets the persisted group id list for all the profiles that are persisted by your app. Your app should call this method every time it adds or deletes a profile from its storage.

## Parameters

*cGroupIDList* \[in\]

The count of group ids being pointed to by *pGroupIDList*.

*pGroupIDList* \[in\]

Pointer to an array of *cGroupIDList* group ids.

## Return value

If the function succeeds, the return value is ERROR\_SUCCESS.

## Remarks

This method is always expected to be called with the entire list, and not a subset. It is OK to call this method with 0 profiles when the profile store is empty.

A re-invoke for a group id that is not part of the provided list will fail with "Fail; unknown P2P Group"(status 8).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| End of client support<br> | Windows 10<br> |
| End of server support<br> | Windows Server 2016<br> |
| Header<br> | Wfdsink.h |
| Library<br> | Wifidisplay.lib |
| DLL<br> | Wifidisplay.dll |

