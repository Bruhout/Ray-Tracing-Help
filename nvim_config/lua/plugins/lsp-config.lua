return {
    {
		"williamboman/mason.nvim",
		config = function()
			require("mason").setup()
		end
	} ,
	{
		"williamboman/mason-lspconfig.nvim",
		config = function()
			require("mason-lspconfig").setup({
				ensure_installed = { "lua_ls" , "clangd" , "autotools_ls" , "basedpyright" }
			})
		end
	} ,
	{
		"neovim/nvim-lspconfig",
		config = function()
			local capabilities = require("cmp_nvim_lsp").default_capabilities()

			local lspconfig = require("lspconfig")
			lspconfig.lua_ls.setup({ capabilities = capabilities })
			lspconfig.clangd.setup({ capabilities = capabilities })
			lspconfig.basedpyright.setup({ capabilities = capabilities })

			vim.keymap.set('n' , "<C-k>" , vim.lsp.buf.hover , {})
			vim.keymap.set('n' , "df" , vim.lsp.buf.definition , {})
			vim.keymap.set('n' , "ca" , vim.lsp.buf.code_action , {})
		end
	}
}
