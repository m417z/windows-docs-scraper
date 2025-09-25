# NdisIMRegisterLayeredMiniport function

## Description

**Note** NDIS 5. *x* has been deprecated and is superseded by NDIS 6. *x*. For new NDIS driver development, see [Network Drivers Starting with Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ddi/_netvista/). For information about porting NDIS 5. *x* drivers to NDIS 6. *x*, see [Porting NDIS 5.x Drivers to NDIS 6.0](https://msdn.microsoft.com/library/Ff570059).

**NdisIMRegisterLayeredMiniport** registers an intermediate driver's *MiniportXxx* entry points and name with the NDIS library when the driver initializes.

## Parameters

### `NdisWrapperHandle` [in]

Specifies the handle returned by [**NdisMInitializeWrapper**](https://msdn.microsoft.com/library/ff553547/(v=vs.85/)).

### `MiniportCharacteristics` [in]

Pointer to an NDIS *XX*\_MINIPORT\_CHARACTERISTICS structure set up by the caller. The structure at *MiniportCharacteristics* is defined as follows:

```cpp
        typedef struct _NDIS_MINIPORT_CHARACTERISTICS {
            UCHAR MajorNdisVersion;
            UCHAR MinorNdisVersion;
            UINT Reserved;
            W_CHECK_FOR_HANG_HANDLER CheckForHangHandler;
            W_DISABLE_INTERRUPT_HANDLER DisableInterruptHandler;
            W_ENABLE_INTERRUPT_HANDLER  EnableInterruptHandler;
            W_HALT_HANDLER HaltHandler;
            W_HANDLE_INTERRUPT_HANDLER  HandleInterruptHandler;
            W_INITIALIZE_HANDLER InitializeHandler;
            W_ISR_HANDLER ISRHandler;
            W_QUERY_INFORMATION_HANDLER QueryInformationHandler;
            W_RECONFIGURE_HANDLER ReconfigureHandler;
            W_RESET_HANDLER ResetHandler;
            W_SEND_HANDLER SendHandler;
            W_SET_INFORMATION_HANDLER SetInformationHandler;
            W_TRANSFER_DATA_HANDLER TransferDataHandler;
        //
        // Version used is V4.0 or V5.0
        // with following members
        //
            W_RETURN_PACKET_HANDLER ReturnPacketHandler;
            W_SEND_PACKETS_HANDLER SendPacketsHandler;
            W_ALLOCATE_COMPLETE_HANDLER AllocateCompleteHandler;
        //
        // Version used is V5.0 with the following members
        //
            W_CO_CREATE_VC_HANDLER CoCreateVcHandler;
            W_CO_DELETE_VC_HANDLER CoDeleteVcHandler;
            W_CO_ACTIVATE_VC_HANDLER CoActivateVcHandler;
            W_CO_DEACTIVATE_VC_HANDLER CoDeactivateVcHandler;
            W_CO_SEND_PACKETS_HANDLER CoSendPacketsHandler;
            W_CO_REQUEST_HANDLER CoRequestHandler;
        //
        // Version used is V5.1 with the following members
        //
            W_CANCEL_SEND_PACKETS_HANDLER CancelSendPacketsHandler;
            W_MINIPORT_PNPEVENTNOTIFY_HANDLER PnPEventNotifyHandler;
            W_MINIPORT_SHUTDOWN_HANDLER AdapterShutdownHandler;
        } NDIS_MINIPORT_CHARACTERISTICS, *PNDIS_MINIPORT_CHARACTERISTICS;
```

An NDIS intermediate driver should initialize this structure with zeros before setting up any of the following members:

- **MajorNdisVersion**
Specifies the major version of the NDIS library the driver is using. The current value is 0x05, although the NDIS library continues to support existing miniport drivers developed for NDIS 4.0.

- **MinorNdisVersion**
Specifies the minor version of the NDIS library the driver is using. The current value is 0x00, although NDIS continues to support existing drivers.

- **Reserved**
This member is reserved for system use.

- **CheckForHangHandler**
Specifies the entry point of the caller's [**MiniportCheckForHang**](https://msdn.microsoft.com/library/ff549367/(v=vs.85/)) function, if any, or **NULL**.

- **DisableInterruptHandler**
Specifies **NULL**.

- **EnableInterruptHandler**
Specifies **NULL**.

- **HaltHandler**
Specifies the entry point of the caller's [**MiniportHalt**](https://msdn.microsoft.com/library/ff549451/(v=vs.85/)) function.

- **HandleInterruptHandler**
Specifies **NULL**.

- **InitializeHandler**
Specifies the entry point of the caller's [**MiniportInitialize**](https://msdn.microsoft.com/library/ff550472/(v=vs.85/)) function.

- **ISRHandler**
Specifies **NULL**.

- **QueryInformationHandler**
Specifies the entry point of the caller's [**MiniportQueryInformation**](https://msdn.microsoft.com/library/ff550490/(v=vs.85/)) function.

- **ReconfigureHandler**
Specifies **NULL**.

- **ResetHandler**
Specifies the entry point of the caller's [*MiniportReset*](https://msdn.microsoft.com/library/ff550502/(v=vs.85/)) function.

- **SendHandler**
Specifies the entry point of the caller's [**MiniportSend**](https://msdn.microsoft.com/library/ff550518/(v=vs.85/)) function, [**MiniportWanSend**](https://msdn.microsoft.com/library/ff550561/(v=vs.85/)) function, or **NULL** if the caller supplies a [**MiniportSendPackets**](https://msdn.microsoft.com/library/ff550524/(v=vs.85/)) function.

 If the driver supports multipacket sends or media-specific information, it sets the **SendPacketsHandler** member instead and sets this member to **NULL**.

- **SetInformationHandler**
Specifies the entry point of the caller's [**MiniportSetInformation**](https://msdn.microsoft.com/library/ff550530/(v=vs.85/)) function.

- **TransferDataHandler**
Specifies the entry point of the caller's [**MiniportTransferData**](https://msdn.microsoft.com/library/ff550556/(v=vs.85/)) function, if any, or **NULL**. This miniport driver function is required unless the caller is the driver of a WAN NIC or the caller supports multipacket receives and, therefore, supplies the entry point of its [**MiniportReturnPacket**](https://msdn.microsoft.com/library/ff550510/(v=vs.85/)) function at **ReturnPacketHandler**.

- **ReturnPacketHandler**
Specifies the entry point of the caller's *MiniportReturnPacket* function, if any, or **NULL**.

- **SendPacketsHandler**
Specifies the entry point of the caller's *MiniportSendPackets* function, if any, or **NULL**.

- **AllocateCompleteHandler**
Specifies **NULL**.

- **CoCreateVcHandler**
Specifies **NULL**.

- **CoDeleteVcHandler**
Specifies **NULL**.

- **CoActivateVcHandler**
Specifies **NULL**.

- **CoDeactivateVcHandler**
Specifies **NULL**.

- **CoSendPacketsHandler**
Specifies **NULL**.

- **CoRequestHandler**
Specifies **NULL**.

- **CancelSendPacketsHandler**
Specifies the entry point of the caller's [**MiniportCancelSendPackets**](https://msdn.microsoft.com/library/ff549359/(v=vs.85/)) function, if any, or **NULL**. Intermediate drivers that queue send packets for more than one second should register a *MiniportCancelSendPackets* function.

- **PnPEventNotifyHandler**
Specifies the entry point of the caller's [**MiniportPnPEventNotify**](https://msdn.microsoft.com/library/ff550487/(v=vs.85/)) function. NDIS 5.1 miniport drivers must register a *MiniportPnPEventNotify* function. Miniport drivers ''that have a WDM lower edge should register a *MiniportPnPEventNotify* function.

- **AdapterShutdownHandler**
Specifies the entry point of the caller's [**MiniportShutdown**](https://msdn.microsoft.com/library/ff550533/(v=vs.85/)) function, if any, or **NULL**. NDIS 5.1 intermediate drivers must register a *MiniportShutdown* function. NDIS 5.1 intermediate drivers should register a *MiniportShutdown* function by calling **NdisIMRegisterLayeredMiniport**--not by calling [**NdisMRegisterAdapterShutdownHandler**](https://msdn.microsoft.com/library/ff553584/(v=vs.85/)).

### `CharacteristicsLength` [in]

Specifies the length in bytes of the caller-supplied characteristics buffer. Depending on the value of **MajorNdisVersion**, this parameter must be either sizeof(NDIS50\_MINIPORT\_CHARACTERISTICS) if the driver supplies an NDIS50\_MINIPORT\_CHARACTERISTICS structure or sizeof(NDIS40\_MINIPORT\_CHARACTERISTICS) if the driver supplies an NDIS40\_MINIPORT\_CHARACTERISTICS structure.

If the driver includes the build instruction NDIS50\_MINIPORT (or NDIS40\_MINIPORT, as appropriate) in its sources or if the driver writer uses the -NDIS50\_MINIPORT (or ..40..) compiler switch, this parameter is set when the driver is built.

### `DriverHandle` [out]

Pointer to a variable in which **NdisIMRegisterLayeredMiniport**, if this call is successful, returns a handle that the caller should save. The caller subsequently must pass this handle to [**NdisIMInitializeDeviceInstance**](https://msdn.microsoft.com/library/ff552161/(v=vs.85/)), usually from its [**ProtocolBindAdapter**](https://msdn.microsoft.com/library/ff562465/(v=vs.85/)) function.

## Return value

**NdisIMRegisterLayeredMiniport** returns NDIS\_STATUS\_SUCCESS if it registered the caller as a miniport driver, or it can return one of the following status values:

|Return code|Description|
|--- |--- |
|**NDIS_STATUS_BAD_CHARACTERISTICS**|The _CharacteristicsLength_ is too small for the **MajorNdisVersion** specified in the buffer at _MiniportCharacteristics_.|
|**NDIS_STATUS_BAD_VERSION**|The **MajorNdisVersion** or **MajorNdisVersion** specified in the characteristics structure is invalid.|
|**NDIS_STATUS_RESOURCES**|A shortage of resources, possibly memory, prevented the NDIS library from registering the caller as a miniport driver.|
|**NDIS_STATUS_FAILURE**|This is a default error status, returned when none of the preceding errors caused the registration to fail. For example, if the NDIS library cannot load the driver's image and lock it into system memory, it returns this error.|

## Remarks

Any NDIS intermediate driver that exports both *MiniportXxx* and *ProtocolXxx* functions sets up a characteristics structure and calls **NdisIMRegisterLayeredMiniport** from its **DriverEntry** function after **DriverEntry** calls [**NdisMInitializeWrapper**](https://msdn.microsoft.com/library/ff553547/(v=vs.85/)). This structure is copied in the **NdisIMRegisterLayeredMiniport** request to the NDIS library's internal storage. Thus, once it has registered, such a driver cannot change its handler functions.

After such an NDIS intermediate driver has called **NdisIMRegisterLayeredMiniport** successfully, it must call [**NdisRegisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocol) to register its *ProtocolXxx* functions with the NDIS library. Such a driver usually has both [**ProtocolBindAdapter**](https://msdn.microsoft.com/library/ff562465/(v=vs.85/)) and [**ProtocolUnbindAdapter**](https://msdn.microsoft.com/library/ff563260/(v=vs.85/)) functions. Its *ProtocolBindAdapter* function will be called next when the underlying NIC driver has initialized successfully. *ProtocolBindAdapter* then can establish a binding to that NIC driver with [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter).

An NDIS intermediate driver should have a [**MiniportSendPackets**](https://msdn.microsoft.com/library/ff550524/(v=vs.85/)) function if an underlying NIC driver might support multipacket sends or consume media-specific information, such as packet priorities, sent down in a packet array from a higher-level protocol. An NDIS intermediate driver should have a [**MiniportReturnPacket**](https://msdn.microsoft.com/library/ff550510/(v=vs.85/)) function if an underlying NIC driver might support multipacket receive indications or indicate packet arrays containing media-specific information. The NDIS library handles packet arrays transferred between an underlying NIC driver and higher-level protocol that support only single-packet transfers on behalf of such an intermediate driver.

- Target platform: [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356)
- Version: Not supported for NDIS 6.0 drivers in Windows Vista. Use [**NdisMRegisterMiniportDriver**](https://msdn.microsoft.com/library/Ff563654)instead. Supported for NDIS 5.1 drivers in Windows Vista and Windows XP.

## See also

- [**DriverEntry of NDIS Miniport Drivers**](https://msdn.microsoft.com/library/Ff548818)
- [**DriverEntry of NDIS Protocol Drivers**](https://msdn.microsoft.com/library/Ff548821)
- [**MiniportCheckForHang**](https://msdn.microsoft.com/library/ff549367/(v=vs.85/))
- [**MiniportHalt**](https://msdn.microsoft.com/library/ff549451/(v=vs.85/))
- [**MiniportInitialize**](https://msdn.microsoft.com/library/ff550472/(v=vs.85/))
- [**MiniportQueryInformation**](https://msdn.microsoft.com/library/ff550490/(v=vs.85/))
- [*MiniportReset*](https://msdn.microsoft.com/library/ff550502/(v=vs.85/))
- [**MiniportReturnPacket**](https://msdn.microsoft.com/library/ff550510/(v=vs.85/))
- [**MiniportSend**](https://msdn.microsoft.com/library/ff550518/(v=vs.85/))
- [**MiniportSendPackets**](https://msdn.microsoft.com/library/ff550524/(v=vs.85/))
- [**MiniportSetInformation**](https://msdn.microsoft.com/library/ff550530/(v=vs.85/))
- [**MiniportTransferData**](https://msdn.microsoft.com/library/ff550556/(v=vs.85/))
- [**MiniportWanSend**](https://msdn.microsoft.com/library/ff550561/(v=vs.85/))
- [**NdisIMInitializeDeviceInstance**](https://msdn.microsoft.com/library/ff552161/(v=vs.85/))
- [**NdisMRegisterAdapterShutdownHandler**](https://msdn.microsoft.com/library/ff553584/(v=vs.85/))
- [**NdisMRegisterMiniport**](https://msdn.microsoft.com/library/ff553602/(v=vs.85/))
- [**NdisOpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenadapter)
- [**NdisRegisterProtocol**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisregisterprotocol)
- [**NdisZeroMemory**](https://msdn.microsoft.com/library/Ff564698)
- [**ProtocolBindAdapter**](https://msdn.microsoft.com/library/ff562465/(v=vs.85/))
- [**ProtocolReceivePacket**](https://msdn.microsoft.com/library/ff563251/(v=vs.85/))
- [**ProtocolUnbindAdapter**](https://msdn.microsoft.com/library/ff563260/(v=vs.85/))