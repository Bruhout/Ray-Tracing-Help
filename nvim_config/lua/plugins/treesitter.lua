return {
	"nvim-treesitter/nvim-treesitter",
	build = ":TSUpdate" ,
	config = function() 
		local config = require("nvim-treesitter.configs")
		config.setup({
			ensure_installed = {"lua" , "c" , "cpp" , "python" , "glsl"},
			highlight = { enable = true },
			enable = { enable = true }
		})
		vim.keymap.set('n', '<C-f>', '<cmd>NvimTreeToggle<cr>', { noremap = true })
	end
}

