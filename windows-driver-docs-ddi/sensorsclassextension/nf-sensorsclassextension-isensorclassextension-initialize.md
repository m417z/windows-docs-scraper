# ISensorClassExtension::Initialize

## Description

The [ISensorClassExtension::Initialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensorclassextension-initialize) method initializes the sensor class extension object.

## Parameters

### `pWdfDeviceUnknown`

IUnknown pointer for the driver class that implements the IWDFDevice interface.

### `pSensorDriverUnknown`

IUnknown pointer for the object that implements the ISensorDriver callback interface.

## Return value

This method returns an HRESULT. Possible values include, but are not limited to, one of the following values. See Remarks.

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The method succeeded. |
| **E_POINTER** | The argument was NULL or the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface is missing.. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_EXISTS)** | The class extension is already initialized. |
| **HRESULT_FROM_WIN32(ERROR_ALREADY_INITIALIZED)** | The class extension is already initialized. |
| **HRESULT_FROM_WIN32(ERROR_NOT_FOUND)** | The WPD_OBJECT_ID for the sensor is not valid. |

## Remarks

First, create the sensor class extension by calling the COM CoCreateInstance method, and then call Initialize. We recommend that you perform these initialization steps when called by UMDF in [IPnpCallbackHardware::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware-onpreparehardware). After Initialize returns, the driver must be ready to receive callbacks from the sensor class extension. The sensor class extension calls [ISensorDriver::OnGetSupportedSensorObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupportedsensorobjects) during initialization. Your driver must be ready to return values for all required properties and data fields before it calls Initialize.

Because the class extension calls your driver during initialization, this method can also return HRESULTs that your driver returns from [ISensorDriver::OnGetSupportedSensorObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nf-sensorsclassextension-isensordriver-ongetsupportedsensorobjects).

## See also

[ISensorClassExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsclassextension/nn-sensorsclassextension-isensorclassextension)