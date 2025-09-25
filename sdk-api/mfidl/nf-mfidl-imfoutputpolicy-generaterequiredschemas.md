# IMFOutputPolicy::GenerateRequiredSchemas

## Description

Retrieves a list of the output protection systems that the output trust authority (OTA) must enforce, along with configuration data for each protection system.

## Parameters

### `dwAttributes` [in]

Describes the output that is represented by the OTA calling this method. This value is a bitwise OR of zero or more of the following flags.

| Value | Meaning |
| --- | --- |
| **MFOUTPUTATTRIBUTE_BUS** | Hardware bus. |
| **MFOUTPUTATTRIBUTE_COMPRESSED** | The output sends compressed data. If this flag is absent, the output sends uncompressed data. |
| **MFOUTPUTATTRIBUTE_BUSIMPLEMENTATION** | Reserved. Do not use. |
| **MFOUTPUTATTRIBUTE_DIGITAL** | The output sends a digital signal. If this flag is absent, the output sends an analog signal. |
| **MFOUTPUTATTRIBUTE_NONSTANDARDIMPLEMENTATION** | Reserved. Do not use. |
| **MFOUTPUTATTRIBUTE_SOFTWARE** | Reserved. Do not use. |
| **MFOUTPUTATTRIBUTE_VIDEO** | The output sends video data. If this flag is absent, the output sends audio data. |

### `guidOutputSubType` [in]

Indicates a specific family of output connectors that is represented by the OTA calling this method. Possible values include the following.

| Value | Meaning |
| --- | --- |
| **MFCONNECTOR_AGP** | AGP bus. |
| **MFCONNECTOR_COMPONENT** | Component video. |
| **MFCONNECTOR_COMPOSITE** | Composite video. |
| **MFCONNECTOR_D_JPN** | Japanese D connector. (Connector conforming to the EIAJ RC-5237 standard.) |
| **MFCONNECTOR_DISPLAYPORT_EMBEDDED** | Embedded DisplayPort connector. |
| **MFCONNECTOR_DISPLAYPORT_EXTERNAL** | External DisplayPort connector. |
| **MFCONNECTOR_DVI** | Digital video interface (DVI) connector. |
| **MFCONNECTOR_HDMI** | High-definition multimedia interface (HDMI) connector. |
| **MFCONNECTOR_LVDS** | Low voltage differential signaling (LVDS) connector.<br><br>A connector using the LVDS interface to connect internally to a display device. The connection between the graphics adapter and the display device is permanent and not accessible to the user. Applications should not enable High-Bandwidth Digital Content Protection (HDCP) for this connector. |
| **MFCONNECTOR_PCI** | PCI bus. |
| **MFCONNECTOR_PCI_Express** | PCI Express bus. |
| **MFCONNECTOR_PCIX** | PCI-X bus. |
| **MFCONNECTOR_SDI** | Audio data sent over a connector via S/PDIF. |
| **MFCONNECTOR_SPDIF** | Serial digital interface connector. |
| **MFCONNECTOR_SVIDEO** | S-Video connector. |
| **MFCONNECTOR_UDI_EMBEDDED** | Embedded Unified Display Interface (UDI). |
| **MFCONNECTOR_UDI_EXTERNAL** | External UDI. |
| **MFCONNECTOR_UNKNOWN** | Unknown connector type. See Remarks. |
| **MFCONNECTOR_VGA** | VGA connector. |
| **MFCONNECTOR_MIRACAST** | Miracast wireless connector.<br><br>Supported in Windows 8.1 and later. |

### `rgGuidProtectionSchemasSupported` [in]

Pointer to an array of GUID values that specify which output protection systems are supported by the OTA that is calling this method.

### `cProtectionSchemasSupported` [in]

Number of elements in the *rgGuidProtectionSchemasSupported* array.

### `ppRequiredProtectionSchemas` [out]

Receives a pointer to the [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) interface of a collection object. The caller must release the interface. Each object in the collection is an [IMFOutputSchema](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputschema) pointer. Each **IMFOutputSchema** pointer defines an output protection system that the OTA must enforce.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The video OTA returns the **MFCONNECTOR_UNKNOWN** connector type unless the Direct3D device is in full-screen mode. (Direct3D windowed mode is not generally a secure video mode.) You can override this behavior by implementing a custom EVR presenter that implements the [IEVRTrustedVideoPlugin](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-ievrtrustedvideoplugin) interface.

## See also

[IMFOutputPolicy](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputpolicy)