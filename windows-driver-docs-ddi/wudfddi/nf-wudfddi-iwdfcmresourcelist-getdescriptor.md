# IWDFCmResourceList::GetDescriptor

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDescriptor** method returns a pointer to a resource descriptor that is contained in this interface's resource list.

## Parameters

### `Index`

A zero-based index into the logical configuration that is contained in this interface's resource list.

## Return value

**GetDescriptor** returns a pointer to a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure.

## Remarks

Drivers typically call **GetDescriptor** from within [OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware), before calling [MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

The [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure is defined in Wudfwdm.h.

For more information about parsing hardware resources, see [Finding and Mapping Hardware Resources in a UMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/finding-and-mapping-hardware-resources-in-umdf-1-x-drivers).

#### Examples

See example code in [IWDFDevice3::MapIoSpace](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-mapiospace).

## See also

[IWDFCmResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfcmresourcelist)