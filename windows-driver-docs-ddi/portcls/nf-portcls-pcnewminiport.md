# PcNewMiniport function

## Description

The **PcNewMiniport** function creates an instance of one of the system-supplied miniport drivers that are built into the PortCls system driver, portcls.sys. A class ID specifies which of these miniport drivers to instantiate. The driver supports a miniport interface that is derived from [IMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiport).

## Parameters

### `OutMiniPort` [out]

Output pointer for the miniport-driver object created by this function. This parameter points to a caller-allocated pointer variable into which the function outputs a reference to the newly created [IMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiport) object. This object is an instance of the miniport driver that is specified by the *ClassId* parameter. Specify a valid, non-NULL pointer value for this parameter.

### `ClassID` [in]

Specifies the miniport interface that is being requested. For more information, see the following Remarks section.

## Return value

**PcNewMiniport** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The system-supplied miniport drivers for MPU-401 UARTs and OPL3 synthesizers can be instantiated by calling **PcNewMiniport** These are built-in miniport drivers that are provided with the portcls.sys system driver. Miniport drivers that are part of a vendor's adapter driver are not created in this way.

The *ClassId* parameter can be set to one of the GUIDs in the following table.

| GUID | System-Supplied Driver |
| --- | --- |
| **CLSID_MiniportDriverDMusUART** | DMusUART miniport driver for MPU-401 synth device. Exposes [IMiniportDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iminiportdmus) interface for use with [IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus) port object. |
| **CLSID_MiniportDriverDMusUARTCapture** | DMusUARTCapture miniport driver for MPU-401 capture device. Exposes [IMiniportDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iminiportdmus) interface for use with [IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus) port object. |
| **CLSID_MiniportDriverFmSynth** | FmSynth miniport driver for FM synth device. Exposes [IMiniportMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidi) interface for use with [IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi) port object. |
| **CLSID_MiniportDriverFmSynthWithVol** | Same as the preceding entry, except that the driver also supports a volume node. |
| **CLSID_MiniportDriverUart** | UART miniport driver for MPU-401 synth device. Exposes [IMiniportMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidi) interface for use with [IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi) port object. Obsolete. |

The first two GUIDs in the preceding table are defined in header file dmusicks.h; the last three are defined in portcls.h.

The DMusUART miniport driver outputs MIDI data to a synth device with a pure MPU-401 MIDI interface. To produce sound, this device needs an external MIDI sound module attached to it.

The DMusUARTCapture miniport driver inputs MIDI data from a capture device with a pure MPU-401 interface.

The FMSynth miniport driver outputs MIDI data to a synth device that implements OPL3-style FM synthesis. The **CLSID_MiniportDriverFmSynth** GUID is appropriate for most FM synth devices. However, devices such as the Windows Sound System that do not provide a hardware volume control after the FM synth should use the **CLSID_MiniportDriverFmSynthWithVol** GUID instead. In Windows Server SP1 and later, the FMSynth miniport driver is available only in 32-bit versions of the operating system.

The UART miniport driver is obsolete. New adapter driver code should use the DMusUART miniport driver, which supersedes UART and implements a superset of its functionality.

Microsoft provides the source code for the DMusUART and FMSynth miniport drivers, which can serve as a starting point for hardware vendors who might need to extend these drivers to manage additional device capabilities. Look in the sample audio drivers in the Windows Driver Kit (WDK).

See [Subdevice Creation](https://learn.microsoft.com/windows-hardware/drivers/audio/subdevice-creation) For more information about creating port and miniport drivers for subdevices.

The *OutMiniport* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiport)

[IMiniportDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iminiportdmus)

[IMiniportMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportmidi)

[IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus)

[IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi)