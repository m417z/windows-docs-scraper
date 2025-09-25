## Description

Returns PScript5's private **DEVMODE** structure to allow its plugins to determine its size.

## Parameters

### `pdm`

Contains the size of the private **DEVMODE** structure.

## Remarks

The macro is defined as follows:

```cpp
#define GET_PSCRIPT5_PRIVATE_DEVMODE_SIZE(pdm) \
    ( ( (pdm)->dmDriverExtra > (FIELD_OFFSET(PSCRIPT5_PRIVATE_DEVMODE, wSize) + sizeof(WORD)) ) ? \
        ((PPSCRIPT5_PRIVATE_DEVMODE)((PBYTE)(pdm) + (pdm)->dmSize))->wSize : 0 )
```