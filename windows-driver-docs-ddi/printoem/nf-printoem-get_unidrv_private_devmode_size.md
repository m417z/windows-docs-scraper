# GET_UNIDRV_PRIVATE_DEVMODE_SIZE macro

## Description

Returns PScript5's private DEVMODE structure to allow its plugins to determine its size.

## Parameters

### `pdm`

Contains the size of the private **DEVMODE** structure.

## Remarks

```cpp
#define GET_UNIDRV_PRIVATE_DEVMODE_SIZE(pdm) \
    ( ( (pdm)->dmDriverExtra > (FIELD_OFFSET(UNIDRV_PRIVATE_DEVMODE, wSize) + sizeof(WORD)) ) ? \
        ((PUNIDRV_PRIVATE_DEVMODE)((PBYTE)(pdm) + (pdm)->dmSize))->wSize : 0 )
```