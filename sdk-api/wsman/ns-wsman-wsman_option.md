# WSMAN_OPTION structure

## Description

Represents a specific option name and value pair. An option that is not understood and has a **mustComply** value of **TRUE** should result in the plug-in operation failing the request with an error.

## Members

### `name`

Specifies the name of the option.

### `value`

Specifies the value of the option.

### `mustComply`

Specifies whether the option must be understood and complied with. If this value is **TRUE**, the plug-in must understand and adhere to the meaning of the option; otherwise, the plug-in must return an error. If this is **FALSE**, the plug-in should ignore the option if it is not understood.