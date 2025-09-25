# _WDF_CHILD_ADDRESS_DESCRIPTION_HEADER structure

## Description

[Applies to KMDF only]

The **WDF_CHILD_ADDRESS_DESCRIPTION_HEADER** structure is a header structure that must be the first member of every [address description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) structure.

## Members

### `AddressDescriptionSize`

The size, in bytes, of a driver-defined structure that contains device address information.

## Remarks

To initialize a **WDF_CHILD_ADDRESS_DESCRIPTION_HEADER** structure, your driver should call [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_address_description_header_init).

The value that the driver specifies for the **AddressDescriptionSize** member must match the value it specifies for the **AddressDescriptionSize** member in its [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure.

Address description structures are driver-defined. The driver must store the structure's size in the **AddressDescriptionSize** member. The size value must include the size of this header structure. For example, a driver might define an address descriptor as follows:

```
typedef struct _IEEE_1394_CHILD_ADDRESS_DESCRIPTION {
  WDF_CHILD_ADDRESS_DESCRIPTION_HEADER  AddressHeader;
  //
  // Current bus generation
  //
  ULONG Generation;
} IEEE_1394_CHILD_ADDRESS_DESCRIPTION, *PIEEE_1394_CHILD_ADDRESS_DESCRIPTION;
```

To set the **AddressDescriptionSize** member for this address descriptor, the driver can use the following code:

```
IEEE_1394_CHILD_ADDRESS_DESCRIPTION Addr_Description;
WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT (&Addr_Description,
                                           sizeof(Addr_Description));
```

For more information about address descriptions, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

## See also

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_address_description_header_init)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config)