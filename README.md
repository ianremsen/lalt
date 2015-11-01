# lalt
Lalt is a lisplike to [AutoHotKey script](http://ahkscript.org) transpiler.

Huge credit to http://www.buildyourownlisp.com which bootstrapped this project and supplies a significant part of the codebase (MPC).

Inspiration goes to [Tom Scott](http://tomscott.com), who touched on the weaknesses of AutoHotKey's scripting language in [this excellent 
video](https://www.youtube.com/watch?v=lIFE7h3m40U).

Overview
--------

Let's face it. If you've used AutoHotKey, you know its capabilities are stellar, but its scripting language is awful.

Lalt will allow you to write this:

```
(on-keypress "^j"
	(msgbox "Wow!")
	(msgbox "this is")
	(run "Notepad.exe")
	(win-activate "Untitled - Notepad")
	(win-wait-active "Untitled - Notepad"
		(send (lines 7 "{!}{enter}"))
		(send-input "inside the ctrl{+}j hotkey")
	)
)
```

Instead of this:

```
^j::
MsgBox Wow!
MsgBox this is
Run, Notepad.exe
winactivate, Untitled - Notepad
WinWaitActive, Untitled - Notepad
send, 7 lines{!}{enter}
sendinput, inside the ctrl{+}j hotkey
Return
```

Download
--------

Snatch the prebuilt binaries [here](https://github.com/ianremsen/lalt/releases/new).
Run in cmd (with the dll in the same directory) as 'lalt repl' to get a REPL, or 'lalt compile file' to convert a lalt file into AHK script (not implemented)

Compiling
---------

To compile you currently require Cygwin and the equivalent libreadline and libcurses.
