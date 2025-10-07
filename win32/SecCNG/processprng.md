# ProcessPrng function

The **ProcessPrng** function retrieves a specified number of random bytes from the user-mode per-processor random number generator.

## Parameters

*pbData* `[out]`

A pointer to a buffer that receives the retrieved bytes.

*cbData*

The number of bytes to retrieve.

## Return value

Always returns **TRUE**.

## Requirements

| Requirement | Value |
|--------|--------|
| Minimum supported client | Windows 8 \[desktop apps only\] |
| Minimum supported server | Windows Server 2008 R2 \[desktop apps only\] |
| DLL | `BCryptPrimitives.dll` |
| APISet | `CngRngExt` |