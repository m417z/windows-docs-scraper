# OBJECT_INFORMATION_CLASS enumeration

## Description

The **OBJECT_INFORMATION_CLASS** enumeration type represents the type of information to supply about a kernel object.

## Constants

### `ObjectBasicInformation:0`

The caller-allocated buffer passed to [**ZwQueryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryobject) in the buffer that **ObjectInformation** points to contains a [**PUBLIC_OBJECT_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_public_object_basic_information) structure.

### `ObjectTypeInformation:2`

The caller-allocated buffer passed to [**ZwQueryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryobject) in the buffer that **ObjectInformation** points to contains a [**PUBLIC_OBJECT_TYPE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-__public_object_type_information) structure.

## See also

[**PUBLIC_OBJECT_BASIC_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_public_object_basic_information)

[**PUBLIC_OBJECT_TYPE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-__public_object_type_information)

[**ZwQueryObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwqueryobject)