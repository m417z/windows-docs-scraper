# PDEBUG_EXTENSION_KNOWN_STRUCT_EX callback function

## Description

The *DebugExtensionKnownStructEx* callback function is called by extensions in order to dump structures that are well known to them.

```cpp
 CALLBACK* PDEBUG_EXTENSION_KNOWN_STRUCT_EX DebugExtensionKnownStructEx;
```

## Parameters

### `Client` [in]

A debug client.

### `Flags` [in]

Flags.

### `Offset` [in]

An offset.

### `TypeName` [in, optional]

The name of a type.

### `Buffer` [out, optional]

An output buffer.

### `BufferChars` [in, out, optional]

A pointer to the length of the output buffer.

## Return value

If this callback function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*DebugExtensionKnownStructEx* is called **PDEBUG_EXTENSION_KNOWN_STRUCT_EX** in the Dbgeng.h header file.