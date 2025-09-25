# DdeSetQualityOfService function

## Description

Specifies the quality of service (QOS) a raw Dynamic Data Exchange (DDE) application desires for future DDE conversations it initiates. The specified QOS applies to any conversations started while those settings are in place. A DDE conversation's quality of service lasts for the duration of the conversation; calls to the **DdeSetQualityOfService** function during a conversation do not affect that conversation's QOS.

## Parameters

### `hwndClient` [in]

Type: **HWND**

A handle to the DDE client window that specifies the source of [WM_DDE_INITIATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-initiate) messages a client will send to start DDE conversations.

### `pqosNew` [in]

Type: **const [SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_quality_of_service)***

A pointer to a [SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_quality_of_service) structure for the desired quality of service values.

### `pqosPrev` [out]

Type: **PSECURITY_QUALITY_OF_SERVICE**

A pointer to a
[SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_quality_of_service) structure that receives the previous quality of service values associated with the window identified by
*hwndClient*.

This parameter is optional. If an application has no interest in
*hwndClient*'s previous QOS values, it should set
*pqosPrev* to **NULL**.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a quality of service has not been specified for a client window,
*hwndClient*, prior to sending a [WM_DDE_INITIATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-initiate) with the
*wParam* set to
*hwndClient*, the system uses the following default quality of service values for the client window:

```
{
   Length = sizeof(SECURITY_QUALITY_OF_SERVICE);
   ImpersonationLevel = SecurityImpersonation;
   ContextTrackingMode = SECURITY_STATIC_TRACKING;
   EffectiveOnly = TRUE;
}
```

Use the **DdeSetQualityOfService** function to associate a different quality of service with the client window. After you change the quality of service, the new settings affect any subsequent conversations that are started. Once an application starts a DDE conversation using a particular quality of service value, it must terminate the conversation and restart the conversation in order to have a different value take effect.

## See also

[About Dynamic Data Exchange](https://learn.microsoft.com/windows/desktop/dataxchg/about-dynamic-data-exchange)

**Conceptual**

**Other Resources**

**Reference**

[SECURITY_QUALITY_OF_SERVICE](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_quality_of_service)

[WM_DDE_INITIATE](https://learn.microsoft.com/windows/desktop/dataxchg/wm-dde-initiate)