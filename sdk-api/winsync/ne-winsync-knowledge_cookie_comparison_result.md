# KNOWLEDGE_COOKIE_COMPARISON_RESULT enumeration

## Description

Represents the possible results when a knowledge cookie is compared with a knowledge object by using [ISyncKnowledge2::CompareToKnowledgeCookie](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nf-winsync-isyncknowledge2-comparetoknowledgecookie).

## Constants

### `KCCR_COOKIE_KNOWLEDGE_EQUAL:0`

The knowledge cookie is equal to the specified knowledge.

### `KCCR_COOKIE_KNOWLEDGE_CONTAINED`

The knowledge cookie is contained by the specified knowledge.

### `KCCR_COOKIE_KNOWLEDGE_CONTAINS`

The knowledge cookie contains the specified knowledge.

### `KCCR_COOKIE_KNOWLEDGE_NOT_COMPARABLE`

The knowledge cookie cannot be compared to the specified knowledge.

## Remarks

A knowledge cookie is a lightweight, read-only representation of knowledge that can be used for fast comparisons when performance is especially important.

## See also

[ISyncKnowledge2 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge2)

[Windows Sync Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-enumerations)