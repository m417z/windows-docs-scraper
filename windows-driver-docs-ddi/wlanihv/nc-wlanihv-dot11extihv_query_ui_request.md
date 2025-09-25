# DOT11EXTIHV_QUERY_UI_REQUEST callback

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The operating system calls the
*Dot11ExtIhvQueryUIRequest* function whenever the connection status changes. When this function is
called, the IHV Extensions DLL returns a
[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure that
the operating system can use for a UI request.

## Parameters

### `hIhvExtAdapter` [in, optional]

The handle used by the IHV Extensions DLL to reference the wireless LAN (WLAN) adapter. This
handle value was specified through a previous call to the
[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter) IHV
Handler function.

### `connectionPhase` [in]

The current connection phase. The data type for this member is the
**DOT11EXT_IHV_CONNECTION_PHASE** enumeration:

#### connection_phase_any

Specifies any connection phase.

#### connection_phase_initial_connection

Specifies the connection phase before the IHV Extensions DLL initiates a pre-association
operation. For more information about the pre-association operation, see
[Pre-Association
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/pre-association-operation-overview).

#### connection_phase_post_l3_connection

Specifies the connection phase after the IHV Extensions DLL completes a post-association
operation. For more information about the post-association operation, see
[Post-Association
Operations](https://learn.microsoft.com/windows-hardware/drivers/network/post-association-operations).

### `ppIhvUIRequest` [out]

The address of a pointer to a
[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure.
The IHV Extensions DLL must allocate a buffer for the DOT11EXT_IHV_UI_REQUEST structure by calling
[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer).

## Return value

If the call succeeds, the function returns ERROR_SUCCESS. Otherwise, it returns an error code
defined in
Winerror.h.

## Prototype

```cpp
DOT11EXTIHV_QUERY_UI_REQUEST Dot11ExtIhvQueryUIRequest;

DWORD APIENTRY Dot11ExtIhvQueryUIRequest(
  _In_opt_ HANDLE                        hIhvExtAdapter,
  _In_     DOT11EXT_IHV_CONNECTION_PHASE connectionPhase,
  _Out_    PDOT11EXT_IHV_UI_REQUEST      *ppIhvUIRequest
)
{ ... }
```

## Remarks

When
*Dot11ExtIhvQueryUIRequest* is called, the IHV Extensions DLL must allocate and return a buffer
formatted as a
[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure.
In this situation, the DLL must follow these guidelines:

* The IHV Extensions DLL must call
  [Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer) to
  allocate the buffer. After the DLL returns from
  *Dot11ExtIhvQueryUIRequest*, the operating system is responsible for calling
  [Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer) to free the
  buffer.
* The IHV Extensions DLL formats the
  [DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request) structure
  for a UI request appropriate for the change in connection status.

  For example, if
  *connectionPhase* is set to
  **connection_phase_initial_connection**, the IHV Extensions DLL could set the members of the
  DOT11EXT_IHV_UI_REQUEST structure to reference a user interface page that notifies the user of the
  start of the connection operation.

## See also

[Dot11ExtAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_allocate_buffer)

[DOT11EXT_IHV_UI_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/ns-wlanihv-_dot11ext_ihv_ui_request)

[Dot11ExtIhvInitAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11extihv_init_adapter)

[Dot11ExtFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlanihv/nc-wlanihv-dot11ext_free_buffer)