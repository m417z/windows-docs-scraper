# SignatureComparison enumeration

## Description

Describes how a type or two signatures compare.

## Constants

### `Unrelated`

The two signatures/types being compared are unrelated.

### `Ambiguous`

One signature/type compares ambiguously against the other. For instance, std::pair<*, int> versus std::pair\<int, *> are ambiguous. There are types that would
match both of these equally well (e.g.: `std::pair<int, int>`)

### `LessSpecific`

One signature/type is less specific than the other. For instance, a comparison of `std::vector<*>` against `std::vector<int>` would yield LessSpecific.

### `MoreSpecific`

One signature/type is more specific than the other. For instance, a comparison of `std::vector<int>` against `std::vector<*>` would yield MoreSpecific.

### `Identical`

The signatures/types are identical.

## Remarks

## See also

[Debugger Data Model C++ Overview](https://learn.microsoft.com/windows-hardware/drivers/debugger/data-model-cpp-overview)