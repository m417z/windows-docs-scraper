# MprAdminMIBBufferFree function

## Description

The
**MprAdminMIBBufferFree** function frees buffers returned by the following functions:

* [MprAdminMIBEntryGet](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentryget)
* [MprAdminMIBEntryGetFirst](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetfirst)
* [MprAdminMIBEntryGetNext](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetnext)

## Parameters

### `pBuffer` [in]

Pointer to a memory buffer to free.

## Return value

If the function succeeds, the return value is NO_ERROR.

If the function fails, the return value is one of the following values.

| Value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The *pBuffer* parameter is **NULL**. |

## See also

[MprAdminMIBEntryGet](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentryget)

[MprAdminMIBEntryGetFirst](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetfirst)

[MprAdminMIBEntryGetNext](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradminmibentrygetnext)

[Router Management MIB Functions](https://learn.microsoft.com/windows/desktop/RRAS/mib-functions)

[Router Management MIB Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-mib-reference)