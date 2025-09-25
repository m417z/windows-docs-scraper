## Description

Defines constants that specify a rounding mode.

## Constants

### `DML_ROUNDING_MODE_HALVES_TO_NEAREST_EVEN`

Specifies rounding to the nearest integer, with tied halves to the nearest even integer.

### `DML_ROUNDING_MODE_TOWARD_ZERO`

Specifies rounding toward zero to the nearest integer.

### `DML_ROUNDING_MODE_TOWARD_INFINITY`

Specifies rounding to the nearest integer, with tied halves toward the nearest infinity / away from zero.

## Remarks

| Original value | -2.5 | -1.75 | -1.5 | -1.25 | 0 | 1.25 | 1.5 | 1.75 | 2.5 |
|------------------------------------------|------|-------|------|-------|---|------|-----|------|-----|
| DML_ROUNDING_MODE_HALVES_TO_NEAREST_EVEN | -2 | -2 | -2 | -1 | 0 | 1 | 2 | 2 | 2 |
| DML_ROUNDING_MODE_TOWARD_ZERO | -2 | -1 | -1 | -1 | 0 | 1 | 1 | 1 | 2 |
| DML_ROUNDING_MODE_TOWARD_INFINITY | -3 | -2 | -2 | -1 | 0 | 1 | 2 | 2 | 3 |

## See also