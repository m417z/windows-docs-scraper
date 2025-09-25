# ITAllocatorProperties::SetAllocatorProperties

## Description

The
**SetAllocatorProperties** method must be called before connection and will force the MSP to use these values during filter negotiation. If the connecting filter doesn't accept these values, the connection is not established.

## Parameters

### `pAllocProperties` [in]

Pointer to the allocator buffer.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## Remarks

**This method should be used with extreme care.** The quality of the sound may suffer if the values entered for this method are not optimal for the MSP. Therefore, the application should know exactly the properties preferred by the MSP before calling this method. Under Windows 2000, properties entered during calls to this method are ignored if they are not optimal. Under Windows XP, these values are not ignored and the application must be more knowledgeable.

If the application is only concerned with setting consistent buffer sizes, the
[ITAllocatorProperties::SetBufferSize](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itallocatorproperties-setbuffersize) method should be used instead. This guarantees the application is provided with the specified buffer size.

## See also

[ITAllocatorProperties](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itallocatorproperties)