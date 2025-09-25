# TAG_TYPE structure

## Description

The
**TAG_TYPE** structure specifies tags used for the
[PreprocessCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-preprocesscommand) function.

## Members

### `pwszTag`

A tag string, in UNICODE.

### `dwRequired`

Specifies whether the tag is required.

| Flag | Meaning |
| --- | --- |
| **NS_REQ_ZERO** | Tag is optional. |
| **NS_REQ_PRESENT** | Tag must be present. |
| **NS_REQ_ALLOW_MULTIPLE** | Multiple copies of the tag is allowed. |
| **NS_REQ_ONE_OR_MORE** | Multiple copies of the tag is allowed. Tag must be present. |

### `bPresent`

This value specifies whether the tag is present. **TRUE** indicates the tag is present.

## See also

[PreprocessCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nf-netsh-preprocesscommand)