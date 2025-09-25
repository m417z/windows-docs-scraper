# IMbnInterface::GetReadyState

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the ready state.

## Parameters

### `readyState` [out, retval]

A pointer to an [MBN_READY_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_ready_state) structure. If this method returns any value other than **S_OK**, this parameter is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *readyState* contains valid values. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing for the ready state. The calling application can get notified when the ready state is available by registering for the [OnReadyStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onreadystatechange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |

## Remarks

The ready state specifies whether the interface is successfully initialized and is ready to perform connection operations. For SIM-based devices, a device is ready when the SIM has been initialized successfully by the device. The device can be used for connection only when the ready state is **MBN_READY_STATE_INITIALIZED**. For more information about other device states, see [MBN_READY_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_ready_state).

The ready state of an interface can change as a result of a user operation. For example, when a user inserts a SIM into a device, the ready state changes from **MBN_READY_STATE_SIM_NOT_INSERTED** to another ready state. The ready state can also change because of other operations performed by the application. For example, when a PIN has been entered, the ready state can change from **MBN_READY_STATE_DEVICE_LOCKED** to another ready state. An application can register for event notifications whenever there is a change in the ready state of the interface. The [OnReadyStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onreadystatechange) member of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents) is called to notify an application about any change in the ready state.

The device's SMS subsystem may not be ready when it reports **MBN_READY_STATE_INITIALIZED**. A calling application should wait for a call to the [OnSmsConfigurationChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnsmsevents-onsmsconfigurationchange) member of [IMbnSmsEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnsmsevents), indicating that the SMS subsystem is ready.

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)