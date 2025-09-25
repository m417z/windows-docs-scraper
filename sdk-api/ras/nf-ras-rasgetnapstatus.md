# RasGetNapStatus function

## Description

The **RasGetNapStatus** function retrieves the [Network Access Protection](https://learn.microsoft.com/windows/desktop/NAP/network-access-protection-start-page) (NAP) connection state variables for a given remote access connection.

## Parameters

### `hRasconn` [in]

A handle to the connection. Use [RasDial](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasdiala) or [RasEnumConnections](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasenumconnectionsa) to obtain this handle.

### `pRasNapState` [in, out]

A pointer to a [RASNAPSTATE](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-rasnapstate) structure. On input, the **dwSize** member of the structure must be set to **sizeof(RASNAPSTATE)**. On output, *pNapState* returns the NAP state of the RAS connection.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is one of the following error codes or a value from [Routing and Remote Access Error Codes](https://learn.microsoft.com/windows/desktop/RRAS/routing-and-remote-access-error-codes) or Winerror.h.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_NAP_CAPABLE** | Connection corresponding to the *hRasConn* parameter is not configured for NAP. |
| **ERROR_INVALID_SIZE** | The *dwSize* parameter of the [RASNAPSTATE](https://learn.microsoft.com/windows/desktop/api/ras/ns-ras-rasnapstate) structure has an invalid size value. |
| **ERROR_INVALID_HANDLE** | Handle passed to the function is either **NULL** or invalid. |
| **ERROR_NO_CONNECTION** | RASMAN could not find the handle in its list of handles. |