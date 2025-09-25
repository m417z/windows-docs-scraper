# BaseValueSource enumeration

## Description

Defines constants that specify where the effective value of a property was set.

## Constants

### `BaseValueSourceUnknown:0`

The source of the property value is not known.

### `BaseValueSourceDefault`

The value has not been set locally or by any styles, so it has the
default value defined in generic.xaml.

### `BaseValueSourceBuiltInStyle`

The value was set by a built-in style.

### `BaseValueSourceStyle`

The value was set by a style.

### `BaseValueSourceLocal`

The value was set locally.

### `Inherited`

The value was inherited from a parent element.

### `DefaultStyleTrigger`

The value was set by a default style trigger.

### `TemplateTrigger`

The value was set by a template style.

### `StyleTrigger`

The value was set by a style trigger.

### `ImplicitStyleReference`

The value was set by an implicit style reference.

### `ParentTemplate`

The value was set by a parent template.

### `ParentTemplateTrigger`

The value was set by a parent template trigger.

### `Animation`

The value was set by an animation.

### `Coercion`

The value was coerced in code.

### `BaseValueSourceVisualState`

The value was set by a visual state. (Introduced in Windows 10, version 1607.)