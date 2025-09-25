# MFINPUTTRUSTAUTHORITY_ACCESS_ACTION structure

## Description

Describes an action requested by an output trust authority (OTA). The request is sent to an input trust authority (ITA).

## Members

### `Action`

Specifies the action as a member of the [MFPOLICYMANAGER_ACTION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfpolicymanager_action) enumeration.

### `pbTicket`

Pointer to a buffer that contains a ticket object, provided by the OTA.

### `cbTicket`

Size of the ticket object, in bytes.

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)