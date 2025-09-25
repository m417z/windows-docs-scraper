## Description

Returns an ordered list of the entry identifiers of containers to be included in the name resolution process initiated by the [IAddrBook::ResolveName](https://learn.microsoft.com/windows/win32/api/wabiab/nf-wabiab-iaddrbook-resolvename) method.

## Parameters

### `ulFlags`

Value of type **ULONG** that specifies the bitmask of flags that control the type of the strings returned in the search path. The following flag is valid for the Windows Address Book (WAB):

| Flag | Description |
|------|-------------|
| MAPI_UNICODE | Specifies that returned strings are formatted in Unicode. If this flag is not set, the strings will be in ANSI format. |

### `lppSearchPath`

Address of a pointer to a variable of type **SRowSet** that specifies the ordered list of container entry identifiers. **IAddrBook::GetSearchPath** stores the ordered list in an **SRowSet** structure. If there are no containers in the address book hierarchy, the method returns zero in the **SRowSet** structure.

## Return value

HRESULT

## Remarks

## See also