# tagDRMRIGHTS structure

## Description

The **DRMRIGHTS** structure specifies the DRM content rights
assigned to a KS audio pin or to a port-class driver's stream object.

## Members

### `CopyProtect`

Specifies one of the following copy-protection values:

#### TRUE

Enables copy protection. An audio application must not do the following:

* Store the content in any form in any nonvolatile storage.
* Pass the content by reference or by value to any other component within the host system that is not
  authenticated by the DRM system.

#### FALSE

Disables copy protection. Content can be copied without restrictions.

For more information about **CopyProtect**, see the Remarks section.

### `Reserved`

Reserved for future use. Initialize to zero.

### `DigitalOutputDisable`

Specifies one of the following digital output protection values:

#### TRUE

Disable digital outputs. A software component must not transfer the content out of the host system through any type of digital interface. Note that digital output protection does not affect USB devices because the host system includes USB devices.

#### FALSE

Enables digital outputs. Content can be transferred from the host system to an external component without restrictions.

For more information about **DigitalOutputDisable**, see the Remarks section.

## Remarks

The Windows Certification Program places specific requirements on the way an audio driver handles the **CopyProtect** and **DigitalOutputDisable** values. These requirements are applicable when the **CopyProtect** and **DigitalOutputDisable** values are applied to an audio stream and to the output from which the audio stream is accessed. New requirements for Windows 7 include the correct way to program the serial copy management system (SCMS) for S/PDIF endpoints, and high-bandwidth digital content protection (HDCP) for HDMI endpoints.

The following table summarizes the content protection state that the driver must establish for different values of **CopyProtect** and **DigitalOutputDisable**.

|  |  |  |  |
| --- | --- | --- | --- |
| **DRMRIGHTS Boolean members** | | **Resulting content protection** | |
| **DigitalOutputDisable** | **CopyProtect** | **HDMI and Display port** | **S/PDIF** |
| False | False | Enabled with no HDCP | Enabled with no SCMS |
| False | True | Enabled with HDCP | Enabled with SCMS |
| True | Don't care | Enabled with HDCP | Disabled |

**Note** If the driver is unable to apply HDCP or SCMS correctly, the driver must disable output to the endpoint.

When an audio driver applies SCMS copy protection to a S/PDIF endpoint, the audio driver uses a combination of the L, Cp, and Category Code bits to select an SCMS state of "Copy Never." For more information about copy protection for digital content, see IEC 60958 available on the [IEC website](https://www.iec.ch/).

If the driver supports DRMRIGHTS and also implements a proprietary copy protection mechanism, the driver must aggregate the result of the proprietary implementation with the values of **CopyProtect** and **DigitalOutputDisable** to determine the final copy protection state. The final copy protection state must be the most restrictive of all outstanding copy protection requests.

The **DEFINE_DRMRIGHTS_DEFAULT** macro defines a constant **DRMRIGHTS** structure that specifies default DRM content rights.

```cpp
VOID DEFINE_DRMRIGHTS_DEFAULT(
   DRMRIGHTS DrmRights
);
```

Parameters

*DrmRights*

**DRMRIGHTS**

Specifies a name for a constant DRMRIGHTS structure. The macro sets the members of *DrmRights* to the following default values:

Return value

**VOID**

This macro does not return a value.

## See also

[DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed)

[DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent)

[DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights)