typedef enum BaseValueSource {
  BaseValueSourceUnknown = 0,
  BaseValueSourceDefault,
  BaseValueSourceBuiltInStyle,
  BaseValueSourceStyle,
  BaseValueSourceLocal,
  Inherited,
  DefaultStyleTrigger,
  TemplateTrigger,
  StyleTrigger,
  ImplicitStyleReference,
  ParentTemplate,
  ParentTemplateTrigger,
  Animation,
  Coercion,
  BaseValueSourceVisualState
} ;