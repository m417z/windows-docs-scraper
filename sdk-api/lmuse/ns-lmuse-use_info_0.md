# USE_INFO_0 structure

## Description

The
**USE_INFO_0** structure contains the name of a shared resource and the local device redirected to it.

## Members

### `ui0_local`

Pointer to a Unicode string that specifies the local device name (for example, drive E or LPT1) being redirected to the shared resource. The constant DEVLEN specifies the maximum number of characters in the string.

### `ui0_remote`

Pointer to a Unicode string that specifies the share name of the remote resource being accessed. The string is in the form:

``` syntax
\\servername\sharename

```

## See also

[NetUseEnum](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netuseenum)

[NetUseGetInfo](https://learn.microsoft.com/windows/desktop/api/lmuse/nf-lmuse-netusegetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Use Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/use-functions)