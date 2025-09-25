# EVT_WDF_CHILD_LIST_IDENTIFICATION_DESCRIPTION_COMPARE callback function

## Description

[Applies to KMDF only]

A driver's *EvtChildListIdentificationDescriptionCompare* event callback function compares one child identification description with another.

## Parameters

### `ChildList` [in]

A handle to a framework child-list object.

### `FirstIdentificationDescription` [in]

A pointer to a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure that identifies the one child identification description.

### `SecondIdentificationDescription` [in]

A pointer to a WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER structure that identifies another child identification description.

## Return value

The *EvtChildListIdentificationDescriptionCompare* callback function must return **TRUE** if the two child identification descriptions match. Otherwise, this function must return **FALSE**.

## Remarks

If a bus driver is using [dynamic enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration), it can register an *EvtChildListIdentificationDescriptionCompare* callback function by calling [WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig) or [WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate). The driver can also register a second, special-case *EvtChildListIdentificationDescriptionCompare* callback function when it calls [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice).

The framework compares two identification descriptions when it must determine if both descriptions identify the same device.

The *EvtChildListIdentificationDescriptionCompare* callback function must compare the contents of two identification descriptions and return **TRUE** if they match. A driver must supply this callback function if the framework cannot call [RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory) to compare the identification descriptions. (The framework cannot call **RtlCompareMemory** if the descriptions contain pointers to additional memory.)

If your driver does not provide an *EvtChildListIdentificationDescriptionCompare* callback function, the framework compares identification descriptions by calling [RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory).

The following steps describe a possible scenario:

1. The driver calls [WdfChildListRetrieveAddressDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrieveaddressdescription) to obtain the address description that is associated with the framework's copy of an identification description, which is stored in a child list.
2. The framework traverses the child list. To determine if a child's identification description matches the one that the driver specified when it called [WdfChildListRetrieveAddressDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrieveaddressdescription), the framework calls either the *EvtChildListIdentificationDescriptionCompare* callback function (if it exists) or [RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory).
3. If the two identification descriptions match (and the comparison returns **TRUE**), the framework stops traversing the list.
4. The framework copies the address description into memory that the driver supplied when it called [WdfChildListRetrieveAddressDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrieveaddressdescription).

The framework can use [RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory) to compare identification descriptions, if each description consists of a single structure with a predetermined size that is specified by the **IdentificationDescriptionSize** member of the [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure. However, sometimes the description must also contain additional information that is stored in dynamically allocated memory. In this case, you will typically define a description structure so that a member points to the dynamically allocated memory, and your driver must provide an *EvtChildListIdentificationDescriptionCompare* callback function.

This callback function determines if two identification descriptions represent the same device. The callback function might not have to compare all of the structure members to make that determination. For example, suppose that an identification description contains a serial number and a set of hardware identifiers, as follows:

```
typedef struct _PDO_IDENTIFICATION_DESCRIPTION {
  WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER Header;
  ULONG DeviceSerialNumber;
  ULONG CchHardwareIds;
  PWCHAR HardwareIds;
} PDO_IDENTIFICATION_DESCRIPTION, *PPDO_IDENTIFICATION_DESCRIPTION;
```

In this case, the *EvtChildListIdentificationDescriptionCompare* callback function probably has to compare only the **DeviceSerialNumber** members to determine if two descriptions represent the same device.

If your driver calls [WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice) to traverse a device list, you can provide an additional *EvtChildListIdentificationDescriptionCompare* callback function that the framework uses when looking for the next description to retrieve. The framework looks for child devices that match driver-supplied [WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)-typed flags. If a driver provides a special *EvtChildListIdentificationDescriptionCompare* callback function, the framework uses the callback function to refine the search. If the driver does not supply a special *EvtChildListIdentificationDescriptionCompare* callback function, the framework does *not* call [RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory)--it simply returns each child device that matches the specified flags.

The only [framework child-list object method](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/) that a driver's *EvtChildListIdentificationDescriptionCompare* callback function can call is [WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice).

The framework acquires an internal child-list object lock before calling the *EvtChildListIdentificationDescriptionCompare**EvtChildListIdentificationDescriptionCompare* callback function. The callback function must only perform operations that are related to the compare operation, such as calling framework memory object methods and accessing object context space. It must not call methods that access other drivers.

For more information about dynamic enumeration, see [Enumerating the Devices on a Bus](https://learn.microsoft.com/windows-hardware/drivers/wdf/enumerating-the-devices-on-a-bus).

## See also

[RtlCompareMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlcomparememory)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_RETRIEVE_CHILD_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ne-wdfchildlist-_wdf_retrieve_child_flags)

[WdfChildListCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistcreate)

[WdfChildListGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistgetdevice)

[WdfChildListRetrieveAddressDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrieveaddressdescription)

[WdfChildListRetrieveNextDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrievenextdevice)

[WdfFdoInitSetDefaultChildListConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nf-wdffdo-wdffdoinitsetdefaultchildlistconfig)