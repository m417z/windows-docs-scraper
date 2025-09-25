# ExtRemoteData::SetShort method

## Description

The **ExtRemoteData** class provides a wrapper around a small section of a target's memory. **ExtRemoteData** automatically retrieves the memory and provides a number of convenience methods.

The **ExtRemoteData** class includes the following constructors and methods:

[ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata(pcstr_ulong64_ulong))

[Set(Typed)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set(constdebug_typed_data))

[Set(Offset Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set)

[Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterscriptablesequentialstream-read)

[Write](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprinterscriptablesequentialstream-write)

[GetData](https://learn.microsoft.com/windows-hardware/test/hlk/testref/9be92a88-98d7-496e-ac6c-0a59432a89d5)

[GetChar](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getchar)

[GetUchar](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getuchar)

[GetBoolean](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getboolean)

[GetStdBool](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getstdbool)

[GetW32Bool](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getw32bool)

[GetShort](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getshort)

[GetUshort](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getushort)

[GetLong](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getlong)

[GetUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getulong)

[GetLong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getlong64)

[GetUlong64](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getulong64)

[GetFloat](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getfloat)

[GetDouble](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getdouble)

[GetLongPtr](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getlongptr)

[GetUlongPtr](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getulongptr)

[GetPtr](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-getptr)

[ReadBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-readbuffer)

[WriteBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-writebuffer)

[GetString](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfailureanalysis-getstring)

```
class ExtRemoteData
{
public:
    PCSTR  m_Name;
    ULONG64  m_Offset;
    bool  m_ValidOffset;
    ULONG  m_Bytes;
    ULONG64  m_Data;
    bool  m_ValidData;
    bool  m_Physical;
    ULONG  m_SpaceFlags;
};
```

**m_Name**

The name given to this instance of **ExtRemoteData**. This name is used to provide meaningful error messages and is set by the constructor, [ExtRemoteData::ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata).

**m_Offset**

The location in the target's memory (virtual or physical) of the region of memory represented by this instance of **ExtRemoteData**. It can be set by the [ExtRemoteData::ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata) constructor or by the [ExtRemoteData::Set(Typed)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set(constdebug_typed_data)) or [ExtRemoteData::Set(Offset Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set) methods.

**m_ValidOffset**

Indicates whether the **m_Offset**location is valid. If **m_ValidOffset** is `false`, the location is not valid and most of the methods for this object will not work. In this case, the [ExtRemoteData::Set(Typed)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set(constdebug_typed_data)) or [ExtRemoteData::Set(Offset Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set) methods can be called to change **m_Offset** to a valid location.

**m_Bytes**

The size, in bytes, of the region of memory represented by this object. It can be set by the
[ExtRemoteData::ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata) constructor
or by the [ExtRemoteData::Set(Typed)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set(constdebug_typed_data)) or [ExtRemoteData::Set(Offset Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set) methods.

**m_Data**

The cached contents of the region of memory specified by this instance of **ExtRemoteData**. Setting this member is optional. If the region of memory is large, it will not be cached.

**m_ValidData**

Indicates whether the **m_Data** cached data is valid. If **m_ValidData** is `false`, the cached data is not valid and most of the methods for this object will not work. In this case, the [ExtRemoteData::Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-read) method can be called to refresh the cached data.

**m_Physical**

Indicates whether the **m_Offset** location is in the target's virtual address space or in its physical address space. If **m_Physical** is `true`, the **m_Offset**location is in the target's physical address space. If **m_Physical** is `false`, the **m_Offset** location is in the target's virtual address space.

**m_SpaceFlags**

The DEBUG_PHYSICAL_*XXX* flags used for accessing physical memory on the target. These flags are only used if **m_Physical** is `true`. For a description of these flags, see the [ReadPhysical2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readphysical2) method.

## Parameters

### `Data`

See description.

## See also

[ExtRemoteData::Set(Typed)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set(constdebug_typed_data))

[ReadPhysical2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugdataspaces4-readphysical2)

[ExtRemoteData::ExtRemoteData](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-extremotedata)

[ExtRemoteData::Set(Offset Bytes)](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-set)

[ExtRemoteData::Read](https://learn.microsoft.com/windows-hardware/drivers/ddi/engextcpp/nf-engextcpp-extremotedata-read)