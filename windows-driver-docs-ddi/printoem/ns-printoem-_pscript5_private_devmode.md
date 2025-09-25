## Description

The **PSCRIPT5_PRIVATE_DEVMODE** structure enables Pscript5 plug-ins to determine the size of the private portion of Pscript5's **DEVMODEW** structure.

## Members

### `wReserved`

Reserved for system use.

### `wSize`

The size, in bytes, of the private portion of Pscript5's [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

## Remarks

For information about the public and private sections of the **DEVMODEW** structure, see [**DEVMODEW**](https://learn.microsoft.com/windows-hardware/drivers/display/the-devmodew-structure).

Printoem.h defines a macro that you can use to determine the size of the private portion of Pscript5's **DEVMODEW** structure.

```cpp
#define GET_PSCRIPT5_PRIVATE_DEVMODE_SIZE(pdm)\
    ( ( (pdm)->dmDriverExtra > (FIELD_OFFSET(PSCRIPT5_PRIVATE_DEVMODE, wSize) + sizeof(WORD)) ) ? \
    ((PPSCRIPT5_PRIVATE_DEVMODE)((PBYTE)(pdm) + (pdm)-> dmSize)) -> wSize : 0 )
```

The *pdm* argument in the **GET_PSCRIPT5_PRIVATE_DEVMODE_SIZE** macro is a pointer to a **DEVMODEW** structure. The macro determines whether the value of the **dmDriverExtra** member of the **DEVMODEW** structure is larger than the byte offset of the **wSize** member of the **PSCRIPT5_PRIVATE_DEVMODE** structure. If so, the macro returns the value of the **wSize** member in the **PSCRIPT5_PRIVATE_DEVMODE** structure. If not, the macro returns zero.

To safely determine the address of the private portion of your plug-in's **DEVMODEW** structure, do the following:

1. Call the **GET_PSCRIPT5_PRIVATE_DEVMODE_SIZE** macro, passing the address of the **DEVMODEW** structure in the call.

1. Verify that (pdm)->dmDriverExtra is larger than the value returned by the macro. (The macro returns the value of the **wSize** member of the PSCRIPT5_PR****IVATE_DEVMODE structure.)

1. Determine the address of the private portion of your plug-in's **DEVMODEW** structure as follows.

```cpp
    pdmPlugin = (PBYTE)(pdm) + (pdm)->dmSize + wSize;
    ```

 The preceding example starts with the address of the public **DEVMODEW** structure (*pdm*), adds the number of bytes of this structure (*pdm-*>**dmSize**), and then adds the size in bytes of the Pscript5 private **DEVMODEW** structure (**wSize**). A plug-in's private **DEVMODEW** data begins at this memory address. If there are multiple plug-ins chained together, the address returned by this example is that of the first plug-in's private **DEVMODEW** data.

 The second plug-in's private **DEVMODEW** data follows the first plug-in's private **DEVMODEW** data, the third plug-in's private **DEVMODEW** data follows that of the second plug-in's private **DEVMODEW** data, and so on. A plug-in developer who needs to determine the address of the *n*-th plug-in's private **DEVMODEW** data must know the sizes of the private **DEVMODEW** data for the first *n* - 1 plug-ins.

1. Verify that the private portion of your plug-in's **DEVMODEW** structure begins with a valid [OEM_DMEXTRAHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oem_dmextraheader) structure.

## See also

[UNIDRV_PRIVATE_DEVMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_unidrv_private_devmode)