# Translation phases
The various character translation, line joining, comment recognition and other early phases of translation must be specified to occur in a certain order. The Standard says that the translation is to proceed as if the phases occurred in this order (there are more phases, but these are the important ones):

1. Trigraph translation.
2. Line joining.
3. Translate comment to space (but not in strings or character constants). At this stage, multiple white spaces may optionally be condensed into one.
4. Translate the program.

Each stage is **completed before the next is started**.