# QOS_EVENT enumeration

## Description

The
**QOS_EVENT** enum describes quality of service (QOS) events. The
[ITQOSEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itqosevent-get_event) method returns a member of this enum to indicate the type of QOS event that occurred.

## Constants

### `QE_NOQOS:1`

QOS is not available.

### `QE_ADMISSIONFAILURE:2`

The QOS request could not be met.

### `QE_POLICYFAILURE:3`

The type of QOS requested is not supported.

### `QE_GENERICERROR:4`

Unspecified QOS error.

### `QE_LASTITEM`

## See also

[ITBasicCallControl::SetQOS](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-setqos)

[ITQOSEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itqosevent)

[ITQOSEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itqosevent-get_event)

[QOS_SERVICE_LEVEL](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-qos_service_level)