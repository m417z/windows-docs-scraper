# _WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER structure

## Description

[Applies to KMDF only]

The **WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER** structure is a header structure that must be the first member of every [identification description](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration) structure.

## Members

### `IdentificationDescriptionSize`

The size, in bytes, of a driver-defined structure that contains device identification information.

## Remarks

To initialize a **WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER** structure, your driver should call [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init).

The value that the driver specifies for the **IdentificationDescriptionSize** member must match the value it specifies for the **IdentificationDescriptionSize** member in its [WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config) structure.

Identification description structures are driver-defined. The driver must store the structure's size in the **IdentificationDescriptionSize** member. The size value must include the size of this header structure. For example, a driver might define an identification descriptor as follows:

```
typedef struct _IEEE_1394_CHILD_ID_DESCRIPTION {
  WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER  IdHeader;
 WCHAR  VendorName[32];
 WCHAR  ModelName[32];
 LONG  UnitSpecId;
 LONG  UnitSoftwareVersion;
} IEEE_1394_CHILD_ID_DESCRIPTION, *PIEEE_1394_CHILD_ID_DESCRIPTION;
```

To set the **IdentificationDescriptionSize** member for this address descriptor, the driver can use the following code:

```
IEEE_1394_CHILD_ID_DESCRIPTION ID_Description;
WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT(&ID_Description,
                                                 sizeof(ID_Description));
```

For more information about identification descriptions, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

## See also

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdf_child_identification_description_header_init)

[WDF_CHILD_LIST_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_list_config)