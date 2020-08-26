" All system-wide defaults are set in $VIMRUNTIME/debian.vim and sourced by
" the call to :runtime you can find below.  If you wish to change any of those
" settings, you should do it in this file (/etc/vim/vimrc), since debian.vim
" will be overwritten everytime an upgrade of the vim packages is performed.
" It is recommended to make changes after sourcing debian.vim since it alters
" the value of the 'compatible' option.

" This line should not be removed as it ensures that various options are
" properly set to work with the Vim-related packages available in Debian.
runtime! debian.vim

" Vim will load $VIMRUNTIME/defaults.vim if the user does not have a vimrc.
" This happens after /etc/vim/vimrc(.local) are loaded, so it will override
" any settings in these files.
" If you don't want that to happen, uncomment the below line to prevent
" defaults.vim from being loaded.
" let g:skip_defaults_vim = 1

" Uncomment the next line to make Vim more Vi-compatible
" NOTE: debian.vim sets 'nocompatible'.  Setting 'compatible' changes numerous
" options, so any other options should be set AFTER setting 'compatible'.
"set compatible

" Vim5 and later versions support syntax highlighting. Uncommenting the next
" line enables syntax highlighting by default.
if has("syntax")
  syntax on
endif

" If using a dark background within the editing area and syntax highlighting
" turn on this option as well
set background=dark

" Set Colorscheme to badwolf. Other options are
" colorscheme solarized
" colorscheme molokai
" colorscheme badwolf
" colorscheme torte
colorscheme desert

" Uncomment the following to have Vim jump to the last position when
" reopening a file
"if has("autocmd")
"  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
"endif

" Uncomment the following to have Vim load indentation rules and plugins
" according to the detected filetype.
if has("autocmd")
  filetype plugin indent on
endif

" The following are commented out as they cause vim to behave a lot
" differently from regular Vi. They are highly recommended though.
"set showcmd		" Show (partial) command in status line.
set showmatch		" Show matching brackets.
"set ignorecase		" Do case insensitive matching
"set smartcase		" Do smart case matching
"set incsearch		" Incremental search
set autowrite		" Automatically save before commands like :next and :make
"set hidden		" Hide buffers when they are abandoned
"set mouse=a		" Enable mouse usage (all modes)
set title		" Set window's title
set number		" Enable line numbering
set relativenumber	" Show line number on current line and relative numbers on all other lines.
set cursorline		" Enable line highlighting where cursor is currently placed
set wildmenu		" Visual autocomplete for command line
set splitright		" Visual autocomplete for command line
set splitbelow		" Visual autocomplete for command line

" Plugin section
execute pathogen#infect()
let g:ycm_clangd_binary_path = "/home/sarthak-trial/Downloads/clang+llvm-10.0.0-x86_64-linux-gnu-ubuntu-18.04/bin/clangd"
" let g:AutoPairsFlyMode = 1	"Enable FlyMode in AutoPairs plugin
set list lcs=tab:\|\ 
autocmd ColorScheme *
	\ hi SpecialKey ctermfg=DarkGrey ctermbg=234 cterm=bold
"autocmd ColorScheme *
"	\ hi CursorLine cterm=underline ctermfg=White ctermbg=none

" Shortcutting split navigation, saving a keypress by mapping
" Ctrl+w+h to Ctrl+h
map <C-h> <C-w>h
map <C-j> <C-w>j
map <C-k> <C-w>k
map <C-l> <C-w>l

" Source a global configuration file if available
if filereadable("/etc/vim/vimrc.local")
  source /etc/vim/vimrc.local
endif
