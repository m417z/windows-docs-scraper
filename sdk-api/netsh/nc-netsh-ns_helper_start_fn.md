# NS_HELPER_START_FN callback function

## Description

The
**NS_HELPER_START_FN** command is the start function for helpers. The start function provides an opportunity for helpers to register contexts and is registered in the
[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext) function. The following is an example of a start function. Be aware that **SampleStartHelper** is a placeholder for the application-defined function name.

## Parameters

### `pguidParent` [in]

The parent under which the helper DLL should be registered.

### `dwVersion` [in]

The version of the parent helper DLL.

## Return value

Returns NO_ERROR upon success. Any other return value indicates an error.

## Remarks

A typical implementation of the start function is as follows:

``` syntax
DWORD WINAPI SampleStartHelper(
    CONST GUID *pguidParent,
    DWORD       dwVersion
)
{
    DWORD dwErr;
    NS_CONTEXT_ATTRIBUTES attMyAttributes;

    ZeroMemory(&attMyAttributes, sizeof(attMyAttributes));
    attMyAttributes.pwszContext   = L"samplecontext";
    attMyAttributes.guidHelper    = g_SampleGuid;
    attMyAttributes.dwVersion     = 1;
    attMyAttributes.dwFlags       = 0;
    attMyAttributes.ulNumTopCmds  = g_ulSampleNumTopCmds;
    attMyAttributes.pTopCmds      = (CMD_ENTRY (*)[])&g_SampleTopCmds;
    attMyAttributes.ulNumGroups   = g_ulSampleCmdGroups;
    attMyAttributes.pCmdGroups    = (CMD_GROUP_ENTRY (*)[])&g_SampleCmdsGroups;
    attMyAttributes.pfnCommitFn   = SampleCommit;
    attMyAttributes.pfnDumpFn     = SampleDump;
    attMyAttributes.pfnConnectFn  = SampleConnect;

    dwErr = RegisterContext( &attMyAttributes );
    return dwErr;
}
```

## See also

[NS_HELPER_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/netsh/ns-netsh-ns_helper_attributes)

[NS_HELPER_STOP_FN](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-ns_helper_stop_fn)

[RegisterContext](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-registercontext)