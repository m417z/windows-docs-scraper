# IWDFDevice3::MapIoSpace

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **MapIoSpace** method maps the given physical address range to system address space and returns a pseudo base address.

## Parameters

### `PhysicalAddress` [in]

Specifies the starting 64-bit physical address of the I/O range to be mapped.

### `NumberOfBytes` [in]

Specifies a value greater than zero, indicating the number of bytes to be mapped.

### `CacheType` [in]

Specifies a [MEMORY_CACHING_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_memory_caching_type) value, which indicates the cache attribute to use to map the physical address range. The MEMORY_CACHING_TYPE enumeration type is defined in Wudfwdm.h.

### `pPseudoBaseAddress` [out]

The address of a location that receives a pointer to the pseudo base address.

## Return value

The method returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

A driver must call this method during device start-up if it receives translated resources of type **CmResourceTypeMemory** in a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure. **MapIoSpace** maps the physical address returned in the resource list to a framework-managed address referred to as the pseudo base address.

 The driver can then use the pseudo base address to access device registers with READ_REGISTER_*Xxx* and WRITE_REGISTER_*Xxx* functions. For an example, see [Reading and Writing to Device Registers in UMDF 1.x Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/reading-and-writing-to-device-registers-in-umdf-1-x-drivers).

A driver that calls **MapIoSpace** must set the **UmdfDirectHardwareAccess** INF directive to **AllowDirectHardwareAccess**.

 If the driver sets the **UmdfRegisterAccessMode** INF directive to **RegisterAccessUsingUserModeMapping**, calling **MapIoSpace** also maps the given physical address range to a user-mode base address range that the driver can subsequently access by calling [GetHardwareRegisterMappedAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-gethardwareregistermappedaddress).

 For more information about INF directives that UMDF drivers can use, see [Specifying WDF Directives in INF Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-wdf-directives-in-inf-files).

The PHYSICAL_ADDRESS type is defined in Wudfwdm.h, as follows:

```
typedef LARGE_INTEGER PHYSICAL_ADDRESS;
```

#### Examples

In the following code example, a UMDF driver uses its [IPnpCallbackHardware2::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware) callback function to examine its memory-mapped register resources and map them into user-mode address space. The example then implements a **WriteToDevice** method that accesses the memory locations. The driver then calls [UnmapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-unmapiospace) from its [IPnpCallbackHardware2::OnReleaseHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onreleasehardware) callback. The driver’s INF file must enable UMDF hardware access feature by setting the **UmdfDirectHardwareAccess** directive to **AllowDirectHardwareAccess**.

```

HRESULT
CMyDevice::OnPrepareHardware(
    __in IWDFDevice3 * pWdfDevice,
    __in IWDFCmResourceList * pRaw,
    __in IWDFCmResourceList * pTrans
    )
{
    PCM_PARTIAL_RESOURCE_DESCRIPTOR desc = NULL;
    PHYSICAL_ADDRESS regBasePA = {0};
    ULONG regLength = 0;
    BOOLEAN found = FALSE;
    HRESULT hr = S_OK;

    //
    // Scan the list to identify our resource.
    //
    for (i=0; i < pWdfResTranslated->GetCount(); i++) {
        desc = (PCM_PARTIAL_RESOURCE_DESCRIPTOR) pTrans->GetDescriptor(i);

        switch (desc->Type) {
            case CmResourceTypeMemory:
                //
                // See if this is the memory resource we’re looking for.
                //
                if (desc->u.Memory.Length == 0x200) {
                    regsBasePA = desc->u.Memory.Start;
                    regsLength = desc->u.Memory.Length;
                    found = TRUE;
                }
                break;

            default:
                // Ignore all other descriptors.
                break;
        }
    }

    //
    // Map the resource. Store the register base in partner device
    // object for later access.
    //
    if (found) {
            hr = pWdfDevice->MapIoSpace(regBasePA,
                                           regLengthlength,
                                           MmNonCached,
                                          (void **)&m_RegBase);
            if (SUCCEEDED(hr)) {
            //
            // Store the register range in partner object. This will
            // be needed for unmapping.
            //
            m_RegLength = regLength;
        }
    }

    …
}

//
// UMDF driver uses one of the register access APIs such as
// WRITE_REGISTER_Xxx or READ_REGISTER_Xxx macros to access device register.
//
VOID
CMyQueue::WriteToDevice(
    __in IWDFDevice3* pWdfDevice,
    __in UCHAR Value
    )
{
    //
    // Write the UCHAR value at offset 2 from register base.
    //
    WRITE_REGISTER_UCHAR(pWdfDevice,
                      (m_MyDevice->m_RegBase)+2,
                       Value);
}

HRESULT
CMyDevice::OnReleaseHardware(
    __in IWDFDevice3 * pWdfDevice,
    __in IWDFCmResourceList * pTrans
    )
{
    //
    // Unmap registers memory resource.
    //
    pWdfDevice->UnmapIoSpace(m_RegBase, m_RegLength);

    return S_OK;
}

```

## See also

[IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3)