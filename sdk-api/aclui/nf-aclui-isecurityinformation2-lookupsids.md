# ISecurityInformation2::LookupSids

## Description

The **LookupSids** method returns the common names corresponding to each of the elements in the specified list of SIDs.

## Parameters

### `cSids` [in]

The number of
pointers to [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures pointed to by *rgpSids*.

### `rgpSids` [in]

A pointer to an array of pointers to [SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid) structures.

### `ppdo` [out]

A pointer to a pointer to a returned data transfer object that contains the common names of the SIDs. Optionally, this parameter also returns the user principal name (UPN) of the SIDs in the *rgpSids* parameter. The data transfer object is a
[SID_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info) structure.

## Return value

Returns S_OK if successful.

Returns a nonzero error code if an error occurs.

## Remarks

Your implementation of **LookupSids** can return E_NOTIMPL if the access control editor is to determine the common names corresponding to the specified SIDs. However, if the access control editor receives any return code other than S_OK, the editor determines this information.

The client must return the common names through the data object using the following format.

```cpp
#include <windows.h>

// HGLOBAL containing SID_INFO_LIST returned by
// ISecurityInformation2::LookupSids
#define CFSTR_ACLUI_SID_INFO_LIST   TEXT("CFSTR_ACLUI_SID_INFO_LIST")

// Data structures corresponding to CFSTR_ACLUI_SID_INFO_LIST
typedef struct _SID_INFO
{
    PSID    pSid;
    PWSTR   pwzCommonName;
    PWSTR   pwzClass;       // Used for selecting icon, for example,
                            // "User" or "Group"
    PWSTR   pwzUPN;         // Optional pointer to a user principal
                            // name
} SID_INFO, *PSID_INFO;

typedef struct _SID_INFO_LIST
{
    ULONG       cItems;
    SID_INFO    aSidInfo[ANYSIZE_ARRAY];
} SID_INFO_LIST, *PSID_INFO_LIST;

```

## See also

[Access Control Editor](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-editor)

[Access Control Editor Functions](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-functions)

[ISecurityInformation2](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation2)

[SID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-sid)

[SID_INFO](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info)

[SID_INFO_LIST](https://learn.microsoft.com/windows/desktop/api/aclui/ns-aclui-sid_info_list)