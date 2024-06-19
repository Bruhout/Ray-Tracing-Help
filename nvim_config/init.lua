vim.cmd("set number")
vim.cmd("set relativenumber")
vim.cmd("set autoindent")
vim.cmd("set tabstop=4")
vim.cmd("set shiftwidth=4")
vim.cmd("set smarttab")
vim.cmd("set softtabstop=4")
vim.cmd("set mouse=a")


vim.keymap.set('n' , "tt" , "<cmd>q<cr>" , {}) --quit
vim.keymap.set('n' , "<C-s>" , "<cmd>w<cr>" , {}) --save

vim.keymap.set('n' , "<C-[>" , "<cmd><<cr>" , {}) --indent back
vim.keymap.set('n' , "<C-]>" , "<cmd>><cr>" , {}) --indent forward

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not (vim.uv or vim.loop).fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable", -- latest stable release
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

local opts = {}

require("lazy").setup("plugins")

require("ibl").setup()
