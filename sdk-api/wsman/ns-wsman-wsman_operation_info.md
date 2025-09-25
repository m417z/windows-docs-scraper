# WSMAN_OPERATION_INFO structure

## Description

Represents a specific resource endpoint for which the plug-in must perform the request.

## Members

### `fragment`

A [WSMAN_FRAGMENT](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_fragment) structure that specifies the subset of data to be used for the operation. This parameter is reserved for future use and is ignored on receipt.

### `filter`

A [WSMAN_FILTER](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_filter) structure that specifies the filtering that is used for the operation. This parameter is reserved for future use and is ignored on receipt.

### `selectorSet`

A [WSMAN_SELECTOR_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_selector_set) structure that identifies the specific resource to use for the request.

### `optionSet`

A [WSMAN_OPTION_SET](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_option_set) structure that specifies the set of options for the request.

### `reserved`

### `version`