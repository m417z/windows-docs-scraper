# SCardAudit function

## Description

The **SCardAudit** function writes event messages to the Windows application log Microsoft-Windows-SmartCard-Audit/Authentication.

## Parameters

### `hContext` [in]

Handle that identifies the resource manager context. The resource manager context can be set by a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function. This parameter cannot be **NULL**.

### `dwEvent` [in]

The event to log.

| Value | Meaning |
| --- | --- |
| **SCARD_AUDIT_CHV_FAILURE**<br><br>0x0 | A smart card holder verification (CHV) attempt failed. |
| **SCARD_AUDIT_CHV_SUCCESS**<br><br>0x1 | A smart card holder verification (CHV) attempt succeeded. |

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected. An application calling the **SCardAudit** function from within a Remote Desktop session will log the event on the remote system.

#### Examples

```cpp
// hContext was set by a previous call to SCardEstablishContext.
lReturn = SCardAudit (hContext,
                      SCARD_AUDIT_CHV_SUCCESS);

if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardAudit - %x\n", lReturn);
    // Take appropriate action
}

```