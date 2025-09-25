# DDREGISTERCALLBACK structure

## Description

The DDREGISTERCALLBACK structure contains the register callback information. This structure is used by both the [DD_DXAPI_REGISTER_CALLBACK](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551502(v=vs.85)) and [DD_DXAPI_UNREGISTER_CALLBACK](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551514(v=vs.85)) function identifiers of the **DxApi** function.

## Members

### `hDirectDraw`

Specifies the Microsoft DirectDraw handle.

### `dwEvents`

Defines the event that should trigger the callback. The values in **dwParam1** and **dwParam2** depend on the event. The following events are defined:

| Event | Description | dwParam1,dwParam2 |
| --- | --- | --- |
| DDEVENT_DISPLAY_VSYNC | Called every time a display V-sync occurs. | unused,<br><br>unused |
| DDEVENT_POSTDOSBOX | Called after returning from a full-screen MS-DOS box or the security dialog box (appears when CTRL+ALT+DELETE is pressed). | unused,<br><br>unused |
| DDEVENT_POSTRESCHANGE | Called after a mode change occurs. | unused,<br><br>unused |
| DDEVENT_PREDOSBOX | Called before entering a full-screen MS-DOS box or the security dialog box (appears when CTRL+ALT+DELETE is pressed). | unused,<br><br>unused |
| DDEVENT_PRERESCHANGE | Called before a mode change occurs. | unused,<br><br>unused |
| DDEVENT_VP_LINE | Sets an IRQ to occur each time the hardware video port writes the specified line and then calls the callback each time the IRQ is triggered. | hVideoPort,<br><br>line |
| DDEVENT_VP_VSYNC | Called each time a hardware video port V-sync occurs. | hVideoPort,<br><br>unused |

### `pfnCallback`

Points to a [pfnCallback](https://learn.microsoft.com/windows/desktop/api/ddkmapi/nc-ddkmapi-lpdd_notifycallback) callback function that is called when the event that is specified by the **dwEvents** member occurs.

### `dwParam1`

Defined by the **dwEvents** member.

### `dwParam2`

Defined by the **dwEvents** member.

### `pContext`

Contains client data that is passed back to the client if the **pfnCallback** callback function is called.

## See also

[DD_DXAPI_REGISTER_CALLBACK](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551502(v=vs.85))

[DD_DXAPI_UNREGISTER_CALLBACK](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551514(v=vs.85))

[DxApi](https://learn.microsoft.com/previous-versions/windows/drivers/display/nf-dxapi-dxapi)