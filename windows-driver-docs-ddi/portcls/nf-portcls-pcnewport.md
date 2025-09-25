# PcNewPort function

## Description

The **PcNewPort** function creates a new system-supplied port-driver object, whose interface (derived from base class [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)) is specified by a class ID.

## Parameters

### `OutPort` [out]

Output pointer for the port-driver object created by this function. This parameter points to a caller-allocated pointer variable into which the function outputs the pointer to the newly created [IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport) object. This object has the port interface that is specified by the *ClassId* parameter. Specify a valid, non-NULL pointer value for this parameter.

### `ClassID` [in]

Specifies the type of port interface that is being requested. For more information, see the following Remarks section.

## Return value

**PcNewPort** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The *ClassId* parameter can be set to one of the GUIDs in the following table.

| Class GUID | Port Interface Name |
| --- | --- |
| **CLSID_PortDMus** | [IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus) |
| **CLSID_PortMidi** | [IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi) |
| **CLSID_PortTopology** | [IPortTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iporttopology) |
| **CLSID_PortWaveCyclic** | [IPortWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavecyclic) |
| **CLSID_PortWavePci** | [IPortWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepci) |
| **CLSID_PortWaveRT** | [IPortWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavert) |

**CLSID_PortDMus** is defined in header file dmusicks.h. The other four GUIDs in the preceding table are defined in portcls.h.

In Microsoft Windows XP and later, the MIDI and DirectMusic port drivers share the same internal software implementation. This means that the **CLSID_PortMidi** GUID is equivalent to **CLSID_PortDMus**.

For more information about creating port and miniport drivers for subdevices, see [Subdevice Creation](https://learn.microsoft.com/windows-hardware/drivers/audio/subdevice-creation).

The *OutPort* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iport)

[IPortDMus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-iportdmus)

[IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi)

[IPortTopology](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iporttopology)

[IPortWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavecyclic)

[IPortWavePci](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepci)

[IPortWaveRT](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavert)