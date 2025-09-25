# IWDFNamedPropertyStore2::DeleteNamedValue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **DeleteNamedValue** method deletes a value name from the registry.

## Parameters

### `pwszName` [in]

A pointer to a **null**-terminated string that contains a registry value name.

## Return value

**DeleteNamedValue** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The caller provided an invalid input argument. |

This method might return one of the other values that Winerror.h contains.

## Remarks

Before a driver calls **DeleteNamedValue**, it must call [IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore) to obtain the [IWDFNamedPropertyStore2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore2) interface.

For more information about accessing the registry, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

#### Examples

The following code example is an [IObjectCleanup::OnCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iobjectcleanup-oncleanup) callback function for a device object. If the driver had previously added a value to the registry's [DEVICEMAP key](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers), the callback function deletes the value.

```
VOID
CMyDevice::OnCleanup(
 IWDFObject*  pWdfObject
)
{
    UNREFERENCED_PARAMETER(pWdfObject);

    if ((m_CreatedLegacyHardwareKey == TRUE) &&
        (m_LegacyHardwarePropertyStore != NULL))
    {
        m_LegacyHardwarePropertyStore->DeleteNamedValue(m_PdoName);
        SAFE_RELEASE(m_LegacyHardwarePropertyStore);
        delete[] m_PdoName;
    }
}
```

## See also

[IWDFNamedPropertyStore2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore2)

[IWDFPropertyStoreFactory::RetrieveDevicePropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfpropertystorefactory-retrievedevicepropertystore)