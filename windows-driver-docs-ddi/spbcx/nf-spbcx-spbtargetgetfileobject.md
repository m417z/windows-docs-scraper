# SpbTargetGetFileObject function

## Description

The **SpbTargetGetFileObject** method accepts, as an input parameter, an SPBTARGET handle to an open target device, and returns a WDFFILEOBJECT handle to this target.

## Parameters

### `Target` [in]

An [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to a target device on the bus.

## Return value

**SpbTargetGetFileObject** returns a WDFFILEOBJECT handle to an open target device on the bus. The method returns NULL if the connection to the target was closed by an [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect) event callback.

## Remarks

Your controller driver can call this method to obtain a WDFFILEOBJECT handle to an open target device on the bus. The SPB controller driver can then use this handle as an input parameter to WDF methods that require such a handle.

**SpbTargetGetFileObject** returns NULL only if the WDFFILEOBJECT handle to the target was closed but, before it closed, the SPB controller driver took an additional reference on the SBPTARGET object to extend its lifetime.

If the connection was closed and the SPB controller driver holds no references to the SPBTARGET object, the SBPTARGET handle is no longer valid. Passing an invalid handle to **SpbTargetGetFileObject** causes a bug check.

After **SpbTargetGetFileObject** returns a WDFFILEOBJECT handle, there is no guarantee that the target connection will remain open unless another object (for example, an active I/O request) holds a reference to the WDFFILEOBJECT object to prevent it from closing unexpectedly. This method is most useful, and, therefore, most likely to be called, when the target connection is guaranteed to be open. Typically, such calls occur during [EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect) and [EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect) callbacks, and during the processing of I/O requests.

## See also

[EvtSpbTargetConnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_connect)

[EvtSpbTargetDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/spbcx/nc-spbcx-evt_spb_target_disconnect)

[SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)