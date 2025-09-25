# NVME_CDW11_FEATURE_ASYNC_EVENT_CONFIG structure

## Description

Contains parameters for the Asynchronous Event Configuration Feature that controls the events that trigger an asynchronous event notification to the host.

The values from this structure are used in the **AsyncEventConfig** field of the [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.CriticalWarnings`

Specifies whether an asynchronous event notification is sent to the host for the corresponding Critical Warning specified in the **CriticalWarning** field of the [SMART / Health Information Log](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_health_info_log).

When the value in this field is set to `1`, an asynchronous event notification is sent when the corresponding **CriticalWarning** field is set to `1` in the SMART / Health Information Log. When the value in this field is set to `0`, an asynchronous event notification is not sent when the corresponding **CriticalWarning** field is set to `1` in the SMART / Health Information Log.

### `DUMMYSTRUCTNAME.NsAttributeNotices`

Specifies whether an asynchronous event notification is sent to the host for a Namespace Attribute change [NVME_ASYNC_NOTICE_NAMESPACE_ATTRIBUTE_CHANGED](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_notice_codes).

When the value in this field is set to `1`, the Namespace Attribute Changed event is sent to the host when this condition occurs. When the value in this field is cleared to `0`, the controller will not send the Namespace Attribute Changed event to the host.

### `DUMMYSTRUCTNAME.FwActivationNotices`

Specifies whether an asynchronous event notification is sent to the host for a Firmware Activation Starting event [NVME_ASYNC_NOTICE_FIRMWARE_ACTIVATION_STARTING](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_notice_codes).

When the value in this field is set to `1`, the Firmware Activation Starting event is sent to the host when this condition occurs. When the value in this field is cleared to `0`, the controller will not send the Firmware Activation Starting event to the host.

### `DUMMYSTRUCTNAME.Reserved0`

### `DUMMYSTRUCTNAME.TelemetryLogNotices`

Specifies whether an asynchronous event notification is sent to the host for a Telemetry Log Changed event [NVME_ASYNC_NOTICE_TELEMETRY_LOG_CHANGED](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_notice_codes).

### `AsUlong`

## Remarks

The Asynchronous Event Configuration Feature can be used to disable reporting events in the case of a persistent condition.

## See also

- [NVME_ASYNC_EVENT_NOTICE_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_async_event_notice_codes)
- [NVME_CDW11_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw11_features)