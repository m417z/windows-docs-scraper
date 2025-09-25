# NS_DLL_INIT_FN callback function

## Description

The
**InitHelperDll** function is called by NetShell to perform an initial loading of a helper.

## Parameters

### `dwNetshVersion` [in]

The version of NetShell.

### `pReserved`

Reserved for future use.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

The
**InitHelperDll** function is the only function NetShell helpers are required to export. Helpers typically call the
[RegisterHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registerhelper) function from within the
**InitHelperDll** function, as shown in the following example:

``` syntax
DWORD
WINAPI
InitHelperDll(
    DWORD      dwNetshVersion,
    PVOID      pReserved
)
{
    NS_HELPER_ATTRIBUTES attMyAttributes;

    attMyAttributes.guidHelper = g_MyGuid;
    attMyAttributes.dwVersion  = 1;
    attMyAttributes.pfnStart   = NetshStartHelper;
    RegisterHelper( NULL, &attMyAttributes );

    return NO_ERROR;
}
```

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[RegisterHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registerhelper)